
void __thiscall FUN_0078ea80(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  
  do {
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + ((param_3 + param_4) / 2) * 4);
    iVar8 = param_3;
    iVar9 = param_4;
    do {
      iVar2 = *(int *)(param_1 + 0xc);
      iVar3 = *(int *)(*(int *)(iVar1 + 0x294) + 0xcc);
      piVar7 = (int *)(iVar2 + iVar8 * 4);
      while( true ) {
        iVar6 = *(int *)(*(int *)(*piVar7 + 0x294) + 0xcc);
        if (iVar6 < 0) {
          iVar6 = *(int *)(*(int *)(*piVar7 + 0x298) + 0xcc);
        }
        if (iVar3 < 0) {
          iVar5 = *(int *)(*(int *)(iVar1 + 0x298) + 0xcc);
        }
        else {
          iVar5 = iVar3;
        }
        if (iVar5 <= iVar6) break;
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 1;
      }
      iVar3 = *(int *)(*(int *)(iVar1 + 0x294) + 0xcc);
      piVar7 = (int *)(iVar2 + iVar9 * 4);
      while( true ) {
        if (iVar3 < 0) {
          iVar6 = *(int *)(*(int *)(iVar1 + 0x298) + 0xcc);
        }
        else {
          iVar6 = iVar3;
        }
        iVar5 = *(int *)(*(int *)(*piVar7 + 0x294) + 0xcc);
        if (iVar5 < 0) {
          iVar5 = *(int *)(*(int *)(*piVar7 + 0x298) + 0xcc);
        }
        if (iVar5 <= iVar6) break;
        iVar9 = iVar9 + -1;
        piVar7 = piVar7 + -1;
      }
      if (iVar9 < iVar8) break;
      iVar8 = iVar8 + 1;
      uVar4 = *(undefined4 *)(iVar2 + -4 + iVar8 * 4);
      *(undefined4 *)(iVar2 + -4 + iVar8 * 4) = *(undefined4 *)(iVar2 + iVar9 * 4);
      iVar9 = iVar9 + -1;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + iVar9 * 4) = uVar4;
    } while (iVar8 <= iVar9);
    if (param_3 < iVar9) {
      FUN_0078ea80(param_2,param_3,iVar9);
    }
    if (param_4 <= iVar8) {
      return;
    }
    param_3 = iVar8;
  } while( true );
}

