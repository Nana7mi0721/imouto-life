
int FUN_00536f90(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 local_20 [16];
  
  if (DAT_00a4b760 == 1) {
    return -1;
  }
  DAT_00a4b760 = 1;
  FUN_005808a0(8,0x9364c,0x28,&LAB_0052fc40,&LAB_0052fc80,L"Font");
  if (DAT_00aba250 == 0) {
    FUN_0057a980();
  }
  FUN_005764b0(&DAT_007d5c7c,1,0x4b0,local_20,0x20,DAT_00aba250);
  DAT_00a4ba9c = local_20[0];
  if (DAT_00a4bcac == 0) {
    FUN_0056d380(&DAT_00a4bcb0,0,0x200);
  }
  DAT_00a4bcac = 0;
  if (DAT_00a4bec0 == 0) {
    DAT_00a4bec4 = -(uint)(DAT_00a4b76c != 0) & 2;
  }
  DAT_00a4bec0 = 0;
  if (DAT_00a4beb0 == 0) {
    DAT_00a4beb4 = 0x10;
  }
  DAT_00a4beb0 = 0;
  if (DAT_00a4beb8 == 0) {
    DAT_00a4bebc = 6;
  }
  DAT_00a4beb8 = 0;
  if (DAT_00a4bec8 == 0) {
    DAT_00a4becc = FUN_0056cec0();
    DAT_00a4bed0 = 1;
  }
  DAT_00a4bec8 = 0;
  if (DAT_00a4bed4 == 0) {
    DAT_00a4bed8 = 1;
  }
  DAT_00a4bed4 = 0;
  if (DAT_00a4bedc == 0) {
    DAT_00a4bee0 = 0;
  }
  DAT_00a4bedc = 0;
  if (DAT_00a4bee4 == 0) {
    DAT_00a4bee8 = 0;
  }
  DAT_00a4bee4 = 0;
  if (DAT_00a4beec == 0) {
    DAT_00a4bef0 = 0;
    DAT_00a4bef4 = 0;
  }
  uVar2 = 0;
  iVar5 = 0;
  DAT_00a4beec = 0;
  iVar4 = 0;
  do {
    cVar1 = '\0';
    for (uVar3 = uVar2; uVar3 != 0; uVar3 = uVar3 & uVar3 - 1) {
      cVar1 = cVar1 + '\x01';
    }
    (&DAT_00a4b77c)[uVar2] = cVar1;
    (&DAT_00a4b88c)[uVar2] = (char)(iVar4 / 0xff);
    (&DAT_00a4b99c)[uVar2] = (char)(iVar5 / 0xff);
    iVar4 = iVar4 + 0x10;
    uVar2 = uVar2 + 1;
    iVar5 = iVar5 + 0x40;
  } while (iVar4 < 0x1000);
  iVar5 = 0;
  iVar4 = 0;
  do {
    if (iVar5 < 1) {
      (&DAT_00a4b87c)[iVar5] = 0;
    }
    else {
      (&DAT_00a4b87c)[iVar5] = (char)iVar5 + '\x01';
    }
    (&DAT_00a4b98c)[iVar5] = (char)(iVar4 / 0xf);
    iVar4 = iVar4 + 0x40;
    iVar5 = iVar5 + 1;
  } while (iVar4 < 0x400);
  FUN_005364a0(0);
  iVar4 = FUN_005e2310();
  return -(uint)(iVar4 != 0);
}

