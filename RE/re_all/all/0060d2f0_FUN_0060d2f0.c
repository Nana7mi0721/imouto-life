
void __thiscall FUN_0060d2f0(int param_1,int param_2,uint param_3,undefined4 param_4,char param_5)

{
  short *psVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 0x44 + param_2 * 4);
  puVar6 = (ushort *)(iVar9 + (param_3 & 0xffff) * 4);
  puVar7 = puVar6 + -2;
  iVar9 = (uint)*(ushort *)(iVar9 + 2 + (param_3 & 0xffff) * 4) * 0x40 + *(int *)(param_1 + 0x3c);
  uVar3 = *puVar7;
  if (*puVar6 < uVar3) {
    do {
      iVar8 = (uint)puVar7[1] * 0x40 + *(int *)(param_1 + 0x3c);
      if ((uVar3 & 1) == 0) {
        psVar1 = (short *)(iVar8 + 0x30 + param_2 * 2);
        *psVar1 = *psVar1 + 1;
      }
      else {
        uVar4 = 1 << ((byte)param_2 & 0x1f) & 3;
        uVar5 = 1 << (sbyte)uVar4 & 3;
        if ((((param_5 != '\0') &&
             (*(ushort *)(iVar8 + 0x30 + uVar4 * 2) <= *(ushort *)(iVar9 + 0x36 + uVar4 * 2))) &&
            (*(ushort *)(iVar9 + 0x30 + uVar4 * 2) <= *(ushort *)(iVar8 + 0x36 + uVar4 * 2))) &&
           ((*(ushort *)(iVar8 + 0x30 + uVar5 * 2) <= *(ushort *)(iVar9 + 0x36 + uVar5 * 2) &&
            (*(ushort *)(iVar9 + 0x30 + uVar5 * 2) <= *(ushort *)(iVar8 + 0x36 + uVar5 * 2))))) {
          (**(code **)(**(int **)(param_1 + 0x5c) + 4))(iVar9,iVar8);
          if (*(int **)(param_1 + 0x60) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x60) + 4))(iVar9,iVar8);
          }
        }
        psVar1 = (short *)(iVar8 + 0x36 + param_2 * 2);
        *psVar1 = *psVar1 + 1;
      }
      psVar1 = (short *)(iVar9 + 0x30 + param_2 * 2);
      *psVar1 = *psVar1 + -1;
      uVar2 = *(undefined4 *)puVar6;
      *(undefined4 *)puVar6 = *(undefined4 *)puVar7;
      *(undefined4 *)puVar7 = uVar2;
      uVar3 = puVar7[-2];
      puVar7 = puVar7 + -2;
      puVar6 = puVar6 + -2;
    } while (*puVar6 < uVar3);
  }
  return;
}

