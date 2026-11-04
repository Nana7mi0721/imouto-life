
void __thiscall FUN_0060dda0(int param_1,int param_2,int param_3,undefined4 param_4,char param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint *puVar9;
  
  iVar4 = *(int *)(param_1 + 0x4c + param_2 * 4);
  puVar7 = (uint *)(iVar4 + param_3 * 8);
  iVar4 = *(int *)(param_1 + 0x44) + *(int *)(iVar4 + 4 + param_3 * 8) * 0x4c;
  uVar5 = puVar7[-2];
  puVar9 = puVar7 + -2;
  if (*puVar7 < uVar5) {
    do {
      iVar2 = *(int *)(param_1 + 0x44) + puVar9[1] * 0x4c;
      if ((uVar5 & 1) == 0) {
        iVar3 = *(int *)(param_1 + 0x44) + puVar7[1] * 0x4c;
        uVar5 = 1 << ((byte)param_2 & 0x1f) & 3;
        uVar6 = 1 << (sbyte)uVar5 & 3;
        if (param_5 != '\0') {
          if ((((*(uint *)(iVar3 + 0x3c + uVar5 * 4) < *(uint *)(iVar2 + 0x30 + uVar5 * 4)) ||
               (*(uint *)(iVar2 + 0x3c + uVar5 * 4) < *(uint *)(iVar3 + 0x30 + uVar5 * 4))) ||
              (*(uint *)(iVar3 + 0x3c + uVar6 * 4) < *(uint *)(iVar2 + 0x30 + uVar6 * 4))) ||
             (*(uint *)(iVar2 + 0x3c + uVar6 * 4) < *(uint *)(iVar3 + 0x30 + uVar6 * 4))) {
            piVar1 = (int *)(iVar2 + 0x30 + param_2 * 4);
            *piVar1 = *piVar1 + 1;
            goto LAB_0060dea3;
          }
          (**(code **)(**(int **)(param_1 + 100) + 8))(iVar3,iVar2,param_4);
          if (*(int **)(param_1 + 0x68) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x68) + 8))(iVar3,iVar2,param_4);
          }
        }
        piVar1 = (int *)(iVar2 + 0x30 + param_2 * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        piVar1 = (int *)(iVar2 + 0x3c + param_2 * 4);
        *piVar1 = *piVar1 + 1;
      }
LAB_0060dea3:
      puVar8 = puVar7 + -2;
      *(int *)(iVar4 + 0x3c + param_2 * 4) = *(int *)(iVar4 + 0x3c + param_2 * 4) + -1;
      uVar5 = *puVar7;
      uVar6 = puVar7[1];
      *puVar7 = *puVar9;
      puVar7[1] = puVar9[1];
      *puVar9 = uVar5;
      puVar9[1] = uVar6;
      uVar5 = puVar9[-2];
      puVar7 = puVar8;
      puVar9 = puVar9 + -2;
    } while (*puVar8 < uVar5);
  }
  return;
}

