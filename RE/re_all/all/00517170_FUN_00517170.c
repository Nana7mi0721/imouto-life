
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00517170(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((DAT_00a37e80 == 0) || (DAT_00a37e80 == 2)) {
    if (DAT_00a37e80 == 0) {
      if (DAT_00a37ef8 == 0) {
        return 0xffffffff;
      }
      iVar1 = (-(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0) * 0x130;
      iVar4 = *(int *)(iVar1 + DAT_00a37ef8 + 0x10);
      iVar1 = *(int *)(iVar1 + 0x14 + DAT_00a37ef8);
    }
    else {
      iVar4 = DAT_00a37e8c;
      iVar1 = DAT_00a37e90;
    }
    if ((DAT_0084c9cc != iVar4) || (DAT_0084c9c8 != iVar1)) {
      DAT_0084c9c8 = iVar1;
      DAT_0084c9cc = iVar4;
    }
    iVar2 = (DAT_00a37e60 * iVar1) / DAT_00a37e64;
    if (iVar2 < iVar4) {
      iVar3 = iVar1;
    }
    else {
      iVar3 = (DAT_00a37e64 * iVar4) / DAT_00a37e60;
      iVar2 = iVar4;
    }
    if ((((DAT_0084c9c4 != iVar2) || (DAT_0084c9c0 != iVar3)) || (DAT_0084c9bc != DAT_00a37e60)) ||
       (DAT_0084c9b8 != DAT_00a37e64)) {
      DAT_0084c9bc = DAT_00a37e60;
      DAT_0084c9b8 = DAT_00a37e64;
      DAT_0084c9c0 = iVar3;
      DAT_0084c9c4 = iVar2;
    }
    DAT_00a37e9c = (iVar4 - iVar2) / 2;
    DAT_00a37ea0 = (iVar1 - iVar3) / 2;
    DAT_00a37ea4 = DAT_00a37e9c + iVar2;
    DAT_00a37ea8 = DAT_00a37ea0 + iVar3;
  }
  return 0;
}

