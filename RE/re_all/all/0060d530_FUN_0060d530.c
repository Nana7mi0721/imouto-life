
void __thiscall FUN_0060d530(int param_1,int param_2,uint param_3,undefined4 param_4,char param_5)

{
  short *psVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  
  puVar11 = (ushort *)(*(int *)(param_1 + 0x44 + param_2 * 4) + (param_3 & 0xffff) * 4);
  iVar3 = *(int *)(param_1 + 0x3c);
  uVar2 = puVar11[1];
  puVar8 = puVar11 + -2;
  uVar5 = *puVar8;
  if (*puVar11 < uVar5) {
    do {
      iVar9 = (uint)puVar8[1] * 0x40 + *(int *)(param_1 + 0x3c);
      if ((uVar5 & 1) == 0) {
        iVar10 = (uint)puVar11[1] * 0x40 + *(int *)(param_1 + 0x3c);
        uVar6 = 1 << ((byte)param_2 & 0x1f) & 3;
        uVar7 = 1 << (sbyte)uVar6 & 3;
        if ((((param_5 != '\0') &&
             (*(ushort *)(iVar9 + 0x30 + uVar6 * 2) <= *(ushort *)(iVar10 + 0x36 + uVar6 * 2))) &&
            (*(ushort *)(iVar10 + 0x30 + uVar6 * 2) <= *(ushort *)(iVar9 + 0x36 + uVar6 * 2))) &&
           ((*(ushort *)(iVar9 + 0x30 + uVar7 * 2) <= *(ushort *)(iVar10 + 0x36 + uVar7 * 2) &&
            (*(ushort *)(iVar10 + 0x30 + uVar7 * 2) <= *(ushort *)(iVar9 + 0x36 + uVar7 * 2))))) {
          (**(code **)(**(int **)(param_1 + 0x5c) + 8))(iVar10,iVar9,param_4);
          if (*(int **)(param_1 + 0x60) != (int *)0x0) {
            (**(code **)(**(int **)(param_1 + 0x60) + 8))(iVar10,iVar9,param_4);
          }
        }
        psVar1 = (short *)(iVar9 + 0x30 + param_2 * 2);
        *psVar1 = *psVar1 + 1;
      }
      else {
        psVar1 = (short *)(iVar9 + 0x36 + param_2 * 2);
        *psVar1 = *psVar1 + 1;
      }
      psVar1 = (short *)((uint)uVar2 * 0x40 + iVar3 + 0x36 + param_2 * 2);
      *psVar1 = *psVar1 + -1;
      uVar4 = *(undefined4 *)puVar11;
      *(undefined4 *)puVar11 = *(undefined4 *)puVar8;
      *(undefined4 *)puVar8 = uVar4;
      uVar5 = puVar8[-2];
      puVar8 = puVar8 + -2;
      puVar11 = puVar11 + -2;
    } while (*puVar11 < uVar5);
  }
  return;
}

