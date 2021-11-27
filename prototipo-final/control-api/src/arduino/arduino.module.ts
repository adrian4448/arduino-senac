import { Module } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { ArduinoController } from './arduino.controller';
import { ArduinoService } from './arduino.service';
import { People, PeopleSchema } from './schema/people.schema';

@Module({
  imports: [
    MongooseModule.forFeature([{ name: People.name, schema: PeopleSchema }]),
  ],
  controllers: [ArduinoController],
  providers: [ArduinoService],
})
export class ArduinoModule {}
