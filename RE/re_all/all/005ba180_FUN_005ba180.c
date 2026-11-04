
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005ba180(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  if ((DAT_00f130dc == 0) && (DAT_00ef7324 == 0)) {
    return 0;
  }
  DAT_00f130dc = 0;
  if (DAT_00f13108 != 0) {
    if (DAT_00f1310c != 0) {
      FUN_005d2020(DAT_00f13108);
    }
    DAT_00f13108 = 0;
  }
  DAT_00f1310c = 0;
  if ((((DAT_00f130e8 != 0) || (DAT_00f130ec != 0)) || (_DAT_00f130f0 != 0.0)) ||
     (((_DAT_00f130f4 != 0.0 || (DAT_00f130fc != 0)) || (DAT_00f13104 != 0)))) {
    iVar2 = FUN_005d29a0(&DAT_00f130e0,&local_4);
    if (iVar2 == 0) {
      DAT_00f1310c = 1;
      DAT_00f13108 = local_4;
      FUN_005d2d70(local_4);
      return 0;
    }
    FUN_0056bca0(&PTR_PTR_007fd4a0);
    return 0xffffffff;
  }
  iVar2 = DAT_00f13100 + (DAT_00f130f8 + (DAT_00f130e0 + DAT_00f130e4 * 4) * 2) * 2;
  if ((&DAT_00f13110)[iVar2] == 0) {
    iVar1 = FUN_005d29a0(&DAT_00f130e0,&local_4);
    if (iVar1 != 0) {
      FUN_0056bca0(&PTR_PTR_007fd4f0);
      return 0xffffffff;
    }
    (&DAT_00f13110)[iVar2] = local_4;
  }
  DAT_00f13108 = (&DAT_00f13110)[iVar2];
  FUN_005d2d70(DAT_00f13108);
  return 0;
}

