import { Module } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';
import { ArduinoModule } from './arduino/arduino.module';

@Module({
  imports: [
    ArduinoModule,
    MongooseModule.forRoot(
      'mongodb+srv://admin:YLgz1RCkjhk10Kuu@cluster0.jvn8j.mongodb.net/arduino?retryWrites=true&w=majority',
    ),
  ],
})
export class AppModule {}
