
void __fastcall FUN_004c25f0(int param_1)

{
  short sVar1;
  undefined4 uVar2;
  int local_2c;
  int local_28;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  
  if (0 < *(short *)(param_1 + 0x90c)) {
    FUN_005160d0(1,(*(short *)(param_1 + 0x90c) * 0xff) / (int)*(short *)(param_1 + 0x90e));
    FUN_005161e0(0xff,0xff,0xff);
    if (*(short *)(param_1 + 0x90a) < 0) {
      sVar1 = 0;
    }
    else {
      sVar1 = *(short *)(param_1 + 0x90a);
    }
    if (sVar1 < 0x100) {
      if (*(short *)(param_1 + 0x90a) < 0) {
        local_14 = 0;
      }
      else {
        local_14 = (int)*(short *)(param_1 + 0x90a);
      }
      local_10 = local_14;
    }
    else {
      local_10 = 0xff;
    }
    if (*(short *)(param_1 + 0x908) < 0) {
      sVar1 = 0;
    }
    else {
      sVar1 = *(short *)(param_1 + 0x908);
    }
    if (sVar1 < 0x100) {
      if (*(short *)(param_1 + 0x908) < 0) {
        local_20 = 0;
      }
      else {
        local_20 = (int)*(short *)(param_1 + 0x908);
      }
      local_1c = local_20;
    }
    else {
      local_1c = 0xff;
    }
    if (*(short *)(param_1 + 0x906) < 0) {
      sVar1 = 0;
    }
    else {
      sVar1 = *(short *)(param_1 + 0x906);
    }
    if (sVar1 < 0x100) {
      if (*(short *)(param_1 + 0x906) < 0) {
        local_2c = 0;
      }
      else {
        local_2c = (int)*(short *)(param_1 + 0x906);
      }
      local_28 = local_2c;
    }
    else {
      local_28 = 0xff;
    }
    uVar2 = FUN_00543f70(local_28,local_1c,local_10,1);
    FUN_00526390(0,0,DAT_0084b230,DAT_0084b234,uVar2);
  }
  return;
}

