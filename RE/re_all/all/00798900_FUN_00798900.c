
undefined4 FUN_00798900(byte *param_1,int param_2,ushort *param_3)

{
  byte bVar1;
  
  if (param_2 < 1) {
    *param_3 = 0xffff;
    return 0xffffffff;
  }
  bVar1 = *param_1;
  if (bVar1 < 0xfc) {
    *param_3 = (ushort)bVar1;
    return 1;
  }
  if (param_2 < 2) {
    *param_3 = 0xffff;
    return 0xffffffff;
  }
  *param_3 = (ushort)bVar1 + (ushort)param_1[1] * 4;
  return 2;
}

