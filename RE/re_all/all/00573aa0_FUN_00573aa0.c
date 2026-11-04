
undefined4 FUN_00573aa0(int *param_1,uint *param_2,int *param_3)

{
  byte *pbVar1;
  uint uVar2;
  
  pbVar1 = (byte *)*param_1;
  if ((*pbVar1 & 0xfc) == 0xd8) {
    *param_2 = (((CONCAT11(*pbVar1,pbVar1[1]) & 0x3ff) * 4 | pbVar1[2] & 3) << 8 | (uint)pbVar1[3])
               + 0x10000;
    *param_1 = *param_1 + 4;
    *param_3 = *param_3 + 2;
    return 1;
  }
  uVar2 = (uint)CONCAT11(*pbVar1,pbVar1[1]);
  *param_2 = uVar2;
  if (uVar2 == 0) {
    return 0;
  }
  *param_1 = *param_1 + 2;
  *param_3 = *param_3 + 1;
  return 1;
}

