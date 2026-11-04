
void FUN_0065a770(byte *param_1,int param_2)

{
  byte *pbVar1;
  uint uVar2;
  
  if (8 < param_2) {
    uVar2 = param_2 - 1U >> 3;
    param_2 = param_2 + uVar2 * -8;
    pbVar1 = param_1;
    do {
      param_1 = pbVar1 + 8;
      *pbVar1 = (&DAT_00804d78)[*pbVar1];
      pbVar1[1] = (&DAT_00804d78)[pbVar1[1]];
      pbVar1[2] = (&DAT_00804d78)[pbVar1[2]];
      pbVar1[3] = (&DAT_00804d78)[pbVar1[3]];
      pbVar1[4] = (&DAT_00804d78)[pbVar1[4]];
      pbVar1[5] = (&DAT_00804d78)[pbVar1[5]];
      pbVar1[6] = (&DAT_00804d78)[pbVar1[6]];
      uVar2 = uVar2 - 1;
      pbVar1[7] = (&DAT_00804d78)[pbVar1[7]];
      pbVar1 = param_1;
    } while (uVar2 != 0);
  }
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      *param_1 = (&DAT_00804d78)[*param_1];
      param_1 = param_1 + 1;
    } while (param_2 != 0);
  }
  return;
}

