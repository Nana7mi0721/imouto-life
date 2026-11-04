
int FUN_006ba120(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  int local_8;
  
  iVar1 = param_1 + 0xc9b4;
  uVar4 = FUN_006bf110(iVar1);
  iVar2 = *(int *)(param_1 + 0xbc);
  uVar3 = *(uint *)(param_1 + 0xc0);
  iVar5 = 0;
  uVar7 = 0;
  local_8 = 0;
  if (uVar3 != 0) {
    do {
      uVar6 = FUN_006ba1e0(iVar1);
      bVar8 = uVar6 < 0x1021;
      do {
        *(byte *)(uVar7 + iVar2) = *(byte *)(uVar7 + iVar2) & 0xfc | ((byte)uVar4 & 1) << 1;
        iVar5 = local_8 + uVar4;
        uVar7 = uVar7 + 1;
        uVar6 = uVar6 - 1;
        local_8 = iVar5;
        if (uVar6 == 0) break;
      } while (uVar7 < uVar3);
      if ((bVar8) || (uVar3 <= uVar7)) {
        uVar4 = (uint)(uVar4 == 0);
      }
      else {
        uVar4 = FUN_006bf110(iVar1);
      }
    } while (uVar7 < uVar3);
  }
  return iVar5;
}

