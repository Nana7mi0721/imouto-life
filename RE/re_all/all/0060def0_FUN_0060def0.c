
void __thiscall FUN_0060def0(int param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  
  iVar4 = *(int *)(param_1 + 0x4c + param_2 * 4);
  puVar8 = (uint *)(iVar4 + param_3 * 8);
  iVar4 = *(int *)(param_1 + 0x44) + *(int *)(iVar4 + 4 + param_3 * 8) * 0x4c;
  uVar6 = puVar8[3];
  puVar5 = puVar8;
  for (; (uVar6 != 0 && (puVar9 = puVar5 + 2, *puVar9 <= *puVar8)); puVar8 = puVar8 + 2) {
    iVar3 = *(int *)(param_1 + 0x44) + uVar6 * 0x4c;
    uVar6 = 1 << ((byte)param_2 & 0x1f) & 3;
    uVar7 = 1 << (sbyte)uVar6 & 3;
    if ((*puVar9 & 1) == 0) {
      if ((((param_5 != '\0') &&
           (*(uint *)(iVar3 + 0x30 + uVar6 * 4) <= *(uint *)(iVar4 + 0x3c + uVar6 * 4))) &&
          (*(uint *)(iVar4 + 0x30 + uVar6 * 4) <= *(uint *)(iVar3 + 0x3c + uVar6 * 4))) &&
         ((*(uint *)(iVar3 + 0x30 + uVar7 * 4) <= *(uint *)(iVar4 + 0x3c + uVar7 * 4) &&
          (*(uint *)(iVar4 + 0x30 + uVar7 * 4) <= *(uint *)(iVar3 + 0x3c + uVar7 * 4))))) {
        iVar1 = *(int *)(param_1 + 0x44) + puVar8[1] * 0x4c;
        (**(code **)(**(int **)(param_1 + 100) + 4))(iVar1,iVar3);
        if (*(int **)(param_1 + 0x68) != (int *)0x0) {
          (**(code **)(**(int **)(param_1 + 0x68) + 4))(iVar1,iVar3);
        }
      }
      piVar2 = (int *)(iVar3 + 0x30 + param_2 * 4);
      *piVar2 = *piVar2 + -1;
    }
    else {
      piVar2 = (int *)(iVar3 + 0x3c + param_2 * 4);
      *piVar2 = *piVar2 + -1;
    }
    *(int *)(iVar4 + 0x3c + param_2 * 4) = *(int *)(iVar4 + 0x3c + param_2 * 4) + 1;
    uVar6 = *puVar8;
    uVar7 = puVar8[1];
    *puVar8 = *puVar9;
    puVar8[1] = puVar5[3];
    *puVar9 = uVar6;
    puVar5[3] = uVar7;
    uVar6 = puVar5[5];
    puVar5 = puVar9;
  }
  return;
}

