
void __thiscall FUN_0060dc40(int param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  
  iVar5 = *(int *)(param_1 + 0x4c + param_2 * 4);
  puVar1 = (uint *)(iVar5 + param_3 * 8);
  iVar5 = *(int *)(param_1 + 0x44) + *(int *)(iVar5 + 4 + param_3 * 8) * 0x4c;
  uVar7 = puVar1[3];
  puVar6 = puVar1;
  do {
    if (uVar7 == 0) {
      return;
    }
    puVar9 = puVar6 + 2;
    if (*puVar1 < *puVar9) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x44) + uVar7 * 0x4c;
    if ((*puVar9 & 1) == 0) {
      piVar2 = (int *)(iVar3 + 0x30 + param_2 * 4);
      *piVar2 = *piVar2 + -1;
    }
    else {
      iVar4 = *(int *)(param_1 + 0x44) + puVar1[1] * 0x4c;
      uVar7 = 1 << ((byte)param_2 & 0x1f) & 3;
      uVar8 = 1 << (sbyte)uVar7 & 3;
      if (param_5 != '\0') {
        if ((((*(uint *)(iVar4 + 0x3c + uVar7 * 4) < *(uint *)(iVar3 + 0x30 + uVar7 * 4)) ||
             (*(uint *)(iVar3 + 0x3c + uVar7 * 4) < *(uint *)(iVar4 + 0x30 + uVar7 * 4))) ||
            (*(uint *)(iVar4 + 0x3c + uVar8 * 4) < *(uint *)(iVar3 + 0x30 + uVar8 * 4))) ||
           (*(uint *)(iVar3 + 0x3c + uVar8 * 4) < *(uint *)(iVar4 + 0x30 + uVar8 * 4))) {
          *(int *)(iVar3 + 0x3c + param_2 * 4) = *(int *)(iVar3 + 0x3c + param_2 * 4) + -1;
          goto LAB_0060dd64;
        }
        (**(code **)(**(int **)(param_1 + 100) + 8))(iVar4,iVar3,param_4);
        if (*(int **)(param_1 + 0x68) != (int *)0x0) {
          (**(code **)(**(int **)(param_1 + 0x68) + 8))(iVar4,iVar3,param_4);
        }
      }
      *(int *)(iVar3 + 0x3c + param_2 * 4) = *(int *)(iVar3 + 0x3c + param_2 * 4) + -1;
    }
LAB_0060dd64:
    *(int *)(iVar5 + 0x30 + param_2 * 4) = *(int *)(iVar5 + 0x30 + param_2 * 4) + 1;
    uVar7 = *puVar1;
    uVar8 = puVar1[1];
    *puVar1 = *puVar9;
    puVar1[1] = puVar6[3];
    *puVar9 = uVar7;
    puVar6[3] = uVar8;
    uVar7 = puVar6[5];
    puVar1 = puVar1 + 2;
    puVar6 = puVar9;
  } while( true );
}

