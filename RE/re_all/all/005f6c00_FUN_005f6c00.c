
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6c00(void)

{
  int iVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  
  iVar1 = -0x71;
  uVar2 = CONCAT44(DAT_00f3e920,DAT_00f3e91c);
  uVar3 = CONCAT44(DAT_00f3e924,DAT_00f3e920);
  uVar5 = _DAT_00f3ef50;
  do {
    uVar2 = uVar2 & 0x8000000080000000 | uVar3 & 0x7fffffff7fffffff;
    uVar6 = uVar3 & 0x100000001;
    uVar4 = uVar5 ^ CONCAT44((uint)(uVar2 >> 0x21),(uint)uVar2 >> 1);
    uVar2 = *(ulonglong *)(&DAT_00f3ecac + iVar1 * 2);
    uVar3 = *(ulonglong *)(&DAT_00f3ecb0 + iVar1 * 2);
    uVar5 = *(ulonglong *)(&DAT_00f3f2e0 + iVar1 * 8);
    *(ulonglong *)(&DAT_00f3eca4 + iVar1 * 2) =
         ~CONCAT44((int)(uVar6 >> 0x20) + -1,(int)uVar6 + -1) & 0x9908b0df9908b0df ^ uVar4;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0);
  DAT_00f3eca4 = (DAT_00f3eca8 & 0x7fffffff | 0xfffffffe) + 1 & 0x9908b0df ^
                 (DAT_00f3eca4 & 0x80000000 | DAT_00f3eca8 & 0x7fffffff) >> 1 ^ DAT_00f3f2d8 ^
                 0x9908b0df;
  DAT_00f3f2dc = DAT_00f3e91c;
  iVar1 = -199;
  uVar2 = CONCAT44(DAT_00f3ecac,DAT_00f3eca8);
  uVar3 = CONCAT44(DAT_00f3ecb0,DAT_00f3ecac);
  uVar5 = CONCAT44(DAT_00f3e920,DAT_00f3e91c);
  do {
    uVar2 = uVar2 & 0x8000000080000000 | uVar3 & 0x7fffffff7fffffff;
    uVar6 = uVar3 & 0x100000001;
    uVar4 = uVar5 ^ CONCAT44((uint)(uVar2 >> 0x21),(uint)uVar2 >> 1);
    uVar2 = *(ulonglong *)(iVar1 * 8 + 0xf3f2e8);
    uVar3 = *(ulonglong *)(&DAT_00f3f2ec + iVar1 * 2);
    uVar5 = *(ulonglong *)((int)&DAT_00f3ef58 + iVar1 * 8 + 4);
    *(ulonglong *)(&DAT_00f3f2e0 + iVar1 * 8) =
         ~CONCAT44((int)(uVar6 >> 0x20) + -1,(int)uVar6 + -1) & 0x9908b0df9908b0df ^ uVar4;
    iVar1 = iVar1 + 1;
  } while (iVar1 != 0);
  iVar1 = -0x138;
  uVar3 = CONCAT44(DAT_00f3e920 >> 0xb,DAT_00f3e91c >> 0xb) ^ CONCAT44(DAT_00f3e920,DAT_00f3e91c);
  uVar2 = CONCAT44(DAT_00f3e928,DAT_00f3e924);
  do {
    uVar2 = CONCAT44((uint)(uVar2 >> 0x2b),(uint)uVar2 >> 0xb) ^ uVar2;
    uVar3 = CONCAT44((int)(uVar3 >> 0x20) << 7,(int)uVar3 << 7) & 0x9d2c56809d2c5680 ^ uVar3;
    uVar2 = CONCAT44((int)(uVar2 >> 0x20) << 7,(int)uVar2 << 7) & 0x9d2c56809d2c5680 ^ uVar2;
    uVar3 = CONCAT44((int)(uVar3 >> 0x20) << 0xf,(int)uVar3 << 0xf) & 0xefc60000efc60000 ^ uVar3;
    uVar4 = CONCAT44((int)(uVar2 >> 0x20) << 0xf,(int)uVar2 << 0xf) & 0xefc60000efc60000 ^ uVar2;
    uVar5 = *(ulonglong *)(&DAT_00f3f2ec + iVar1 * 2);
    *(ulonglong *)(&DAT_00f3e91c + iVar1 * 2) =
         uVar3 ^ CONCAT44((uint)(uVar3 >> 0x32),(uint)uVar3 >> 0x12);
    uVar2 = *(ulonglong *)(&DAT_00f3f2f4 + iVar1 * 8);
    *(ulonglong *)(&DAT_00f3e924 + iVar1 * 2) =
         uVar4 ^ CONCAT44((uint)(uVar4 >> 0x32),(uint)uVar4 >> 0x12);
    uVar3 = CONCAT44((uint)(uVar5 >> 0x2b),(uint)uVar5 >> 0xb) ^ uVar5;
    iVar1 = iVar1 + 2;
  } while (iVar1 != 0);
  _DAT_00f3df58 = 0;
  return;
}

