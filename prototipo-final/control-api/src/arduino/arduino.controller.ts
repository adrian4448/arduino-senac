import { Controller, Get } from '@nestjs/common';
import { ArduinoService } from './arduino.service';

@Controller('arduino')
export class ArduinoController {
  constructor(private readonly arduinoService: ArduinoService) {}

  @Get()
  async getAllRegisters() {
    return await this.arduinoService.getAllRegisters();
  }

  @Get('/count')
  async countPeople() {
    return await this.arduinoService.countNewPeople();
  }
}
