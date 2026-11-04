
uint FUN_0052ed00(ushort *param_1,int param_2,undefined4 *param_3)

{
  ushort uVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    *param_3 = 2;
    return 0;
  }
  if (param_2 == 0x4b0) {
    uVar2 = (uint)*param_1;
    if ((*param_1 & 0xfc00) != 0xd800) {
LAB_0052ed88:
      *param_3 = 2;
      return uVar2;
    }
    uVar1 = param_1[1];
  }
  else {
    uVar2 = (uint)CONCAT11((byte)*param_1,*(byte *)((int)param_1 + 1));
    if (((byte)*param_1 & 0xfc) != 0xd8) goto LAB_0052ed88;
    uVar1 = CONCAT11((byte)param_1[1],*(byte *)((int)param_1 + 3));
  }
  *param_3 = 4;
  return (uVar1 & 0x3ff | (uVar2 & 0x3ff) << 10) + 0x10000;
}

