
/* WARNING: Removing unreachable block (ram,0x0052eb88) */
/* WARNING: Removing unreachable block (ram,0x0052ebc0) */

undefined4 FUN_0052eb30(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong lVar4;
  
  lVar3 = FUN_00550090(0);
  param_1 = param_1 * 1000;
  if (4000 < param_1) {
    uVar2 = (uint)(lVar3 + param_1);
    iVar1 = FUN_0052ece0();
    while ((iVar1 == 0 &&
           (lVar4 = FUN_00550090(0),
           lVar4 < CONCAT44((int)((ulonglong)(lVar3 + param_1) >> 0x20) - (uint)(uVar2 < 4000),
                            uVar2 - 4000)))) {
      FUN_0056da20(1);
      iVar1 = FUN_0052ece0();
    }
  }
  do {
    lVar4 = FUN_00550090(0);
  } while (lVar4 < lVar3 + param_1);
  return 0;
}

