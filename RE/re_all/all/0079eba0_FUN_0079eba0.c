
void FUN_0079eba0(short *param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  short sVar2;
  short sStack_12;
  short sStack_e;
  short sStack_a;
  short sStack_6;
  short local_4;
  short local_2;
  
  if (param_3 < 1) {
    sStack_a = 0;
    param_3._2_2_ = 0;
  }
  else {
    sStack_a = FUN_007a2170(param_2,&DAT_00837d7c + (byte)(&DAT_00837e14)[param_3],8);
    param_3._2_2_ = (short)param_3 - sStack_a;
  }
  if (sStack_a < 1) {
    sStack_e = 0;
    sStack_a = 0;
  }
  else {
    sStack_e = FUN_007a2170(param_2,&DAT_00837ce4 + (byte)(&DAT_00837e14)[sStack_a],8);
    sStack_a = sStack_a - sStack_e;
  }
  if (sStack_e < 1) {
    sVar1 = 0;
    sStack_e = 0;
  }
  else {
    sVar1 = FUN_007a2170(param_2,&DAT_00837c4c + (byte)(&DAT_00837e14)[sStack_e],8);
    sStack_e = sStack_e - sVar1;
  }
  if (sVar1 < 1) {
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    sVar2 = FUN_007a2170(param_2,&DAT_00837bb4 + (byte)(&DAT_00837e14)[sVar1],8);
    *param_1 = sVar2;
    param_1[1] = sVar1 - sVar2;
  }
  if (sStack_e < 1) {
    param_1[2] = 0;
    param_1[3] = 0;
  }
  else {
    sVar1 = FUN_007a2170(param_2,&DAT_00837bb4 + (byte)(&DAT_00837e14)[sStack_e],8);
    param_1[2] = sVar1;
    param_1[3] = sStack_e - sVar1;
  }
  if (sStack_a < 1) {
    sVar1 = 0;
    sStack_a = 0;
  }
  else {
    sVar1 = FUN_007a2170(param_2,&DAT_00837c4c + (byte)(&DAT_00837e14)[sStack_a],8);
    sStack_a = sStack_a - sVar1;
  }
  if (sVar1 < 1) {
    param_1[4] = 0;
    param_1[5] = 0;
  }
  else {
    sVar2 = FUN_007a2170(param_2,&DAT_00837bb4 + (byte)(&DAT_00837e14)[sVar1],8);
    param_1[4] = sVar2;
    param_1[5] = sVar1 - sVar2;
  }
  if (sStack_a < 1) {
    param_1[6] = 0;
    param_1[7] = 0;
  }
  else {
    sVar1 = FUN_007a2170(param_2,&DAT_00837bb4 + (byte)(&DAT_00837e14)[sStack_a],8);
    param_1[6] = sVar1;
    param_1[7] = sStack_a - sVar1;
  }
  if (param_3._2_2_ < 1) {
    sStack_6 = 0;
    sStack_12 = 0;
  }
  else {
    sStack_6 = FUN_007a2170(param_2,&DAT_00837ce4 + (byte)(&DAT_00837e14)[param_3._2_2_],8);
    sStack_12 = param_3._2_2_ - sStack_6;
  }
  if (sStack_6 < 1) {
    sVar1 = 0;
    sStack_6 = 0;
  }
  else {
    sVar1 = FUN_007a2170(param_2,&DAT_00837c4c + (byte)(&DAT_00837e14)[sStack_6],8);
    sStack_6 = sStack_6 - sVar1;
  }
  if (sVar1 < 1) {
    param_1[8] = 0;
    param_1[9] = 0;
  }
  else {
    sVar2 = FUN_007a2170(param_2,&DAT_00837bb4 + (byte)(&DAT_00837e14)[sVar1],8);
    param_1[8] = sVar2;
    param_1[9] = sVar1 - sVar2;
  }
  FUN_0079eeb0(param_1 + 10,param_1 + 0xb,param_2,(int)sStack_6,&DAT_00837bb4);
  FUN_0079eeb0(&local_4,&local_2,param_2,(int)sStack_12,&DAT_00837c4c);
  FUN_0079eeb0(param_1 + 0xc,param_1 + 0xd,param_2,(int)local_4,&DAT_00837bb4);
  FUN_0079eeb0(param_1 + 0xe,param_1 + 0xf,param_2,(int)local_2,&DAT_00837bb4);
  return;
}

