
void __thiscall FUN_007912b0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  do {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + ((param_3 + param_4) / 2) * 8);
    iVar6 = param_4;
    iVar7 = param_3;
    do {
      iVar2 = *(int *)(param_1 + 0xc);
      piVar8 = (int *)(iVar2 + iVar7 * 8);
      iVar3 = *(int *)(iVar2 + iVar7 * 8);
      while (iVar3 < iVar1) {
        piVar8 = piVar8 + 2;
        iVar7 = iVar7 + 1;
        iVar3 = *piVar8;
      }
      piVar8 = (int *)(iVar2 + iVar6 * 8);
      iVar3 = *(int *)(iVar2 + iVar6 * 8);
      while (iVar1 < iVar3) {
        piVar8 = piVar8 + -2;
        iVar6 = iVar6 + -1;
        iVar3 = *piVar8;
      }
      if (iVar6 < iVar7) break;
      uVar4 = *(undefined4 *)(iVar2 + iVar7 * 8);
      uVar5 = *(undefined4 *)(iVar2 + 4 + iVar7 * 8);
      *(undefined4 *)(iVar2 + iVar7 * 8) = *(undefined4 *)(iVar2 + iVar6 * 8);
      *(undefined4 *)(iVar2 + 4 + iVar7 * 8) = *(undefined4 *)(iVar2 + 4 + iVar6 * 8);
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + -1;
      iVar2 = *(int *)(param_1 + 0xc);
      *(undefined4 *)(iVar2 + 8 + iVar6 * 8) = uVar4;
      *(undefined4 *)(iVar2 + 0xc + iVar6 * 8) = uVar5;
    } while (iVar7 <= iVar6);
    if (param_3 < iVar6) {
      FUN_007912b0(param_2,param_3,iVar6);
    }
    if (param_4 <= iVar7) {
      return;
    }
    param_3 = iVar7;
  } while( true );
}

