
int FUN_006bed70(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  bVar1 = param_3 < 1;
  iVar5 = 1;
  bVar2 = true;
  uVar9 = param_3 + 1;
  iVar6 = 2;
  do {
    if (bVar2) {
      param_3 = iVar5;
    }
    iVar5 = iVar5 + 1;
    uVar9 = uVar9 + 1;
    bVar2 = false;
    iVar8 = 0;
    iVar7 = 0;
    if (0 < param_2) {
      do {
        uVar4 = (uint)*(byte *)(param_1 + 1 + iVar8 * 2);
        if ((int)uVar4 < (int)uVar9) {
          iVar8 = iVar8 + 1;
        }
        else if (uVar4 == uVar9) {
          bVar2 = true;
          iVar8 = iVar8 + 1;
        }
        else {
          iVar3 = FUN_006bed20(param_1 + iVar8 * 2,uVar9);
          iVar8 = iVar8 + iVar3;
        }
        iVar7 = iVar7 + 1;
      } while (iVar8 < param_2);
    }
  } while ((iVar6 < iVar7) &&
          (iVar6 = iVar7, 1 << ((byte)iVar5 & 0x1f) <= (int)(iVar7 * ((bVar1 - 1 & 0xfffffffb) + 7))
          ));
  return param_3;
}

