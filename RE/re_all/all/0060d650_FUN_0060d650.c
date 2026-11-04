
void __thiscall
FUN_0060d650(int param_1,int param_2,ushort *param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  short *psVar2;
  ushort uVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  
  iVar8 = *(int *)(param_1 + 0x44 + param_2 * 4);
  puVar9 = (ushort *)(iVar8 + ((uint)param_3 & 0xffff) * 4);
  uVar3 = puVar9[3];
  iVar8 = (uint)*(ushort *)(iVar8 + 2 + ((uint)param_3 & 0xffff) * 4) * 0x40 +
          *(int *)(param_1 + 0x3c);
  puVar5 = puVar9;
  for (; (uVar3 != 0 && (param_3 = puVar5 + 2, *param_3 <= *puVar9)); puVar9 = puVar9 + 2) {
    iVar1 = (uint)uVar3 * 0x40 + *(int *)(param_1 + 0x3c);
    uVar6 = 1 << ((byte)param_2 & 0x1f) & 3;
    uVar7 = 1 << (sbyte)uVar6 & 3;
    if ((*param_3 & 1) == 0) {
      if ((((param_5 != '\0') &&
           (*(ushort *)(iVar1 + 0x30 + uVar6 * 2) <= *(ushort *)(iVar8 + 0x36 + uVar6 * 2))) &&
          (*(ushort *)(iVar8 + 0x30 + uVar6 * 2) <= *(ushort *)(iVar1 + 0x36 + uVar6 * 2))) &&
         ((*(ushort *)(iVar1 + 0x30 + uVar7 * 2) <= *(ushort *)(iVar8 + 0x36 + uVar7 * 2) &&
          (*(ushort *)(iVar8 + 0x30 + uVar7 * 2) <= *(ushort *)(iVar1 + 0x36 + uVar7 * 2))))) {
        iVar10 = (uint)puVar9[1] * 0x40 + *(int *)(param_1 + 0x3c);
        (**(code **)(**(int **)(param_1 + 0x5c) + 4))(iVar10,iVar1);
        if (*(int **)(param_1 + 0x60) != (int *)0x0) {
          (**(code **)(**(int **)(param_1 + 0x60) + 4))(iVar10,iVar1);
        }
      }
      psVar2 = (short *)(iVar1 + 0x30 + param_2 * 2);
      *psVar2 = *psVar2 + -1;
    }
    else {
      psVar2 = (short *)(iVar1 + 0x36 + param_2 * 2);
      *psVar2 = *psVar2 + -1;
    }
    psVar2 = (short *)(iVar8 + 0x36 + param_2 * 2);
    *psVar2 = *psVar2 + 1;
    uVar4 = *(undefined4 *)puVar9;
    *(undefined4 *)puVar9 = *(undefined4 *)param_3;
    *(undefined4 *)param_3 = uVar4;
    uVar3 = puVar5[5];
    puVar5 = param_3;
  }
  return;
}

