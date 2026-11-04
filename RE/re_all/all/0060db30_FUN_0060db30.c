
void __thiscall FUN_0060db30(int param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  iVar3 = *(int *)(param_1 + 0x4c + param_2 * 4);
  puVar7 = (uint *)(iVar3 + param_3 * 8);
  puVar6 = puVar7 + -2;
  iVar3 = *(int *)(param_1 + 0x44) + *(int *)(iVar3 + 4 + param_3 * 8) * 0x4c;
  uVar4 = *puVar6;
  if (*puVar7 < uVar4) {
    do {
      iVar2 = *(int *)(param_1 + 0x44) + puVar6[1] * 0x4c;
      if ((uVar4 & 1) == 0) {
        piVar1 = (int *)(iVar2 + 0x30 + param_2 * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        uVar4 = 1 << ((byte)param_2 & 0x1f) & 3;
        uVar5 = 1 << (sbyte)uVar4 & 3;
        if ((((param_5 != '\0') &&
             (*(uint *)(iVar2 + 0x30 + uVar4 * 4) <= *(uint *)(iVar3 + 0x3c + uVar4 * 4))) &&
            (*(uint *)(iVar3 + 0x30 + uVar4 * 4) <= *(uint *)(iVar2 + 0x3c + uVar4 * 4))) &&
           ((*(uint *)(iVar2 + 0x30 + uVar5 * 4) <= *(uint *)(iVar3 + 0x3c + uVar5 * 4) &&
            (*(uint *)(iVar3 + 0x30 + uVar5 * 4) <= *(uint *)(iVar2 + 0x3c + uVar5 * 4))))) {
          (**(code **)(**(int **)(param_1 + 100) + 4))(iVar3,iVar2);
          if (*(int **)(param_1 + 0x68) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x68) + 4))(iVar3,iVar2);
          }
        }
        *(int *)(iVar2 + 0x3c + param_2 * 4) = *(int *)(iVar2 + 0x3c + param_2 * 4) + 1;
      }
      puVar8 = puVar7 + -2;
      *(int *)(iVar3 + 0x30 + param_2 * 4) = *(int *)(iVar3 + 0x30 + param_2 * 4) + -1;
      uVar4 = *puVar7;
      uVar5 = puVar7[1];
      *puVar7 = *puVar6;
      puVar7[1] = puVar6[1];
      *puVar6 = uVar4;
      puVar6[1] = uVar5;
      uVar4 = puVar6[-2];
      puVar6 = puVar6 + -2;
      puVar7 = puVar8;
    } while (*puVar8 < uVar4);
  }
  return;
}

