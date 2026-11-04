
void FUN_006ba220(uint param_1)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar3 = *(uint *)(param_1 + 0xc0);
  pbVar4 = *(byte **)(param_1 + 0xbc);
  uVar8 = 0;
  bVar2 = *pbVar4;
  while ((bVar2 & 2) != 0) {
    iVar1 = uVar8 + 1;
    uVar8 = uVar8 + 1;
    bVar2 = pbVar4[iVar1];
  }
  iVar1 = param_1 + 0xc9b4;
  param_1 = FUN_006bf110(iVar1);
  do {
    uVar6 = FUN_006ba1e0(iVar1);
    uVar5 = uVar6;
    for (; uVar8 < uVar3; uVar8 = uVar8 + 1) {
      bVar2 = pbVar4[uVar8];
      uVar7 = uVar5;
      if ((bVar2 & 2) == 0) {
        uVar7 = uVar5 - 1;
        if (uVar5 == 0) break;
        pbVar4[uVar8] = (bVar2 ^ (byte)param_1) & 1 ^ bVar2;
      }
      uVar5 = uVar7;
    }
    if ((uVar6 < 0x1021) || (uVar3 <= uVar8)) {
      param_1 = (uint)(param_1 == 0);
    }
    else {
      param_1 = FUN_006bf110(iVar1);
    }
    if (uVar3 <= uVar8) {
      return;
    }
  } while( true );
}

