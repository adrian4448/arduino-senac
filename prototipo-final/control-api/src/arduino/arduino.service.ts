import { Injectable } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { Model } from 'mongoose';
import { People, PeopleDocument } from './schema/people.schema';

@Injectable()
export class ArduinoService {
  constructor(
    @InjectModel(People.name)
    private readonly peopleModel: Model<PeopleDocument>,
  ) {}

  async getAllRegisters() {
    return await this.peopleModel.find();
  }

  async countNewPeople() {
    const enterDay = new Date().toLocaleDateString();
    const onePeopleEnterOnThisDay = await this.peopleModel
      .findOne({ date: enterDay })
      .exec();
    if (onePeopleEnterOnThisDay) {
      onePeopleEnterOnThisDay.count = onePeopleEnterOnThisDay.count + 1;
      return await onePeopleEnterOnThisDay.save();
    } else {
      const newPeopleOnDay = new this.peopleModel(new People());
      newPeopleOnDay.count = 1;
      newPeopleOnDay.date = enterDay;
      return await newPeopleOnDay.save();
    }
  }
}
