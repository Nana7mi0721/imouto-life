
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6df0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_00f3f2e4 != 0) {
    FUN_005f6c00();
    return;
  }
  iVar3 = -0xe3;
  uVar2 = DAT_00f3e91c;
  uVar4 = DAT_00f3e920;
  do {
    uVar1 = uVar2 & 0x80000000;
    uVar2 = (&DAT_00f3ecac)[iVar3];
    (&DAT_00f3eca8)[iVar3] =
         (uVar4 & 0x7fffffff | 0xfffffffe) + 1 & 0x9908b0df ^
         (uVar1 | uVar4 & 0x7fffffff) >> 1 ^ (&DAT_00f3f2dc)[iVar3] ^ 0x9908b0df;
    uVar4 = (&DAT_00f3ecb0)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0);
  DAT_00f3f2dc = DAT_00f3e91c;
  iVar3 = -0x18d;
  uVar2 = DAT_00f3eca8;
  uVar4 = DAT_00f3ecac;
  do {
    uVar1 = uVar2 & 0x80000000;
    uVar2 = *(uint *)(&DAT_00f3f2e0 + iVar3 * 4);
    (&DAT_00f3f2dc)[iVar3] =
         (uVar4 & 0x7fffffff | 0xfffffffe) + 1 & 0x9908b0df ^
         (uVar1 | uVar4 & 0x7fffffff) >> 1 ^ (&DAT_00f3ef50)[iVar3] ^ 0x9908b0df;
    uVar4 = (&DAT_00f3f2e4)[iVar3];
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0);
  iVar3 = -0x138;
  uVar2 = DAT_00f3e91c;
  do {
    uVar2 = uVar2 >> 0xb ^ uVar2;
    uVar4 = *(uint *)(&DAT_00f3f2e0 + iVar3 * 8) >> 0xb ^ *(uint *)(&DAT_00f3f2e0 + iVar3 * 8);
    uVar2 = (uVar2 & 0x13a58ad) << 7 ^ uVar2;
    uVar4 = (uVar4 & 0x13a58ad) << 7 ^ uVar4;
    uVar2 = (uVar2 & 0x1df8c) << 0xf ^ uVar2;
    uVar4 = (uVar4 & 0x1df8c) << 0xf ^ uVar4;
    (&DAT_00f3e91c)[iVar3 * 2] = uVar2 >> 0x12 ^ uVar2;
    (&DAT_00f3e920)[iVar3 * 2] = uVar4 >> 0x12 ^ uVar4;
    uVar2 = (&DAT_00f3f2e4)[iVar3 * 2];
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0);
  _DAT_00f3df58 = 0;
  return;
}

