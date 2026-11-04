
void __thiscall FUN_006368c0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_8;
  
  do {
    local_8 = param_4;
    iVar1 = *(int *)(*(int *)(param_1 + 0xc) + ((param_4 + param_3) / 2) * 4);
    iVar8 = param_3;
    do {
      iVar2 = *(int *)(param_1 + 0xc);
      iVar3 = *(int *)(*(int *)(iVar1 + 0x14) + 0xcc);
      piVar7 = (int *)(iVar2 + iVar8 * 4);
      while( true ) {
        if (iVar3 < 0) {
          iVar6 = *(int *)(*(int *)(iVar1 + 0x18) + 0xcc);
        }
        else {
          iVar6 = iVar3;
        }
        iVar5 = *(int *)(*(int *)(*piVar7 + 0x14) + 0xcc);
        if (iVar5 < 0) {
          iVar5 = *(int *)(*(int *)(*piVar7 + 0x18) + 0xcc);
        }
        if (iVar6 <= iVar5) break;
        iVar8 = iVar8 + 1;
        piVar7 = piVar7 + 1;
      }
      iVar3 = *(int *)(*(int *)(iVar1 + 0x14) + 0xcc);
      piVar7 = (int *)(iVar2 + local_8 * 4);
      while( true ) {
        iVar6 = *(int *)(*(int *)(*piVar7 + 0x14) + 0xcc);
        if (iVar6 < 0) {
          iVar6 = *(int *)(*(int *)(*piVar7 + 0x18) + 0xcc);
        }
        if (iVar3 < 0) {
          iVar5 = *(int *)(*(int *)(iVar1 + 0x18) + 0xcc);
        }
        else {
          iVar5 = iVar3;
        }
        if (iVar6 <= iVar5) break;
        local_8 = local_8 + -1;
        piVar7 = piVar7 + -1;
      }
      if (local_8 < iVar8) break;
      uVar4 = *(undefined4 *)(iVar2 + iVar8 * 4);
      *(undefined4 *)(iVar2 + iVar8 * 4) = *(undefined4 *)(iVar2 + local_8 * 4);
      iVar8 = iVar8 + 1;
      *(undefined4 *)(*(int *)(param_1 + 0xc) + local_8 * 4) = uVar4;
      local_8 = local_8 + -1;
    } while (iVar8 <= local_8);
    if (param_3 < local_8) {
      FUN_006368c0(param_2,param_3,local_8);
    }
    if (param_4 <= iVar8) {
      return;
    }
    param_3 = iVar8;
  } while( true );
}

