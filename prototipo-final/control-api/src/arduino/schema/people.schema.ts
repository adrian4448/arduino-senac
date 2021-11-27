import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';

export type PeopleDocument = People & Document;

@Schema()
export class People {
  @Prop()
  count: number;
  @Prop()
  date: string;
}

export const PeopleSchema = SchemaFactory.createForClass(People);
