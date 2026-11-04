
void __thiscall FUN_004bf5b0(int param_1,char param_2,char param_3,int param_4)

{
  undefined4 uVar1;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_8;
  
  if (param_3 == '\0') {
    if (param_2 == '\0') {
      if (((*(short *)(param_1 + 0x8f0) < 1) || (*(short *)(param_1 + 0x8f2) < 1)) ||
         (*(short *)(param_1 + 0x8f4) < 1)) {
        if (*(short *)(param_1 + 0x8f4) < 1) {
          local_10 = *(short *)(param_1 + 0x8f4) + 0xff;
        }
        else {
          local_10 = 0xff;
        }
        if (*(short *)(param_1 + 0x8f2) < 1) {
          local_14 = *(short *)(param_1 + 0x8f2) + 0xff;
        }
        else {
          local_14 = 0xff;
        }
        if (*(short *)(param_1 + 0x8f0) < 1) {
          local_18 = *(short *)(param_1 + 0x8f0) + 0xff;
        }
        else {
          local_18 = 0xff;
        }
        FUN_005161e0(local_18,local_14,local_10);
        if (param_4 != 0) {
          for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
            if (*(short *)(param_1 + 0x8f0 + local_8 * 2) < 1) {
              local_1c = *(short *)(param_1 + 0x8f0 + local_8 * 2) + 0xff;
            }
            else {
              local_1c = 0xff;
            }
            *(int *)(param_4 + local_8 * 4) = local_1c;
          }
        }
      }
    }
    else {
      FUN_005160d0(2,0xff);
      FUN_005161e0(0xff,0xff,0xff);
      if (((0 < *(short *)(param_1 + 0x8f0)) || (0 < *(short *)(param_1 + 0x8f2))) ||
         (0 < *(short *)(param_1 + 0x8f4))) {
        if (*(short *)(param_1 + 0x8f4) < 0) {
          local_20 = 0;
        }
        else {
          if (*(short *)(param_1 + 0x8f4) < 0x100) {
            local_24 = (int)*(short *)(param_1 + 0x8f4);
          }
          else {
            local_24 = 0xff;
          }
          local_20 = local_24;
        }
        if (*(short *)(param_1 + 0x8f2) < 0) {
          local_28 = 0;
        }
        else {
          if (*(short *)(param_1 + 0x8f2) < 0x100) {
            local_2c = (int)*(short *)(param_1 + 0x8f2);
          }
          else {
            local_2c = 0xff;
          }
          local_28 = local_2c;
        }
        if (*(short *)(param_1 + 0x8f0) < 0) {
          local_30 = 0;
        }
        else {
          if (*(short *)(param_1 + 0x8f0) < 0x100) {
            local_34 = (int)*(short *)(param_1 + 0x8f0);
          }
          else {
            local_34 = 0xff;
          }
          local_30 = local_34;
        }
        uVar1 = FUN_00543f70(local_30,local_28,local_20,1);
        FUN_00526390(0,0,DAT_0084b230,DAT_0084b234,uVar1);
      }
    }
  }
  else {
    FUN_005161e0(0xff,0xff,0xff);
  }
  return;
}

