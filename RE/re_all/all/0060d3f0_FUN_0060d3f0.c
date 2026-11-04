
void __thiscall
FUN_0060d3f0(int param_1,int param_2,ushort *param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  short *psVar2;
  ushort uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  ushort *puVar10;
  int iVar11;
  
  iVar5 = *(int *)(param_1 + 0x3c);
  puVar10 = (ushort *)(*(int *)(param_1 + 0x44 + param_2 * 4) + ((uint)param_3 & 0xffff) * 4);
  uVar3 = puVar10[3];
  uVar4 = puVar10[1];
  puVar7 = puVar10;
  while( true ) {
    if (uVar3 == 0) {
      return;
    }
    param_3 = puVar7 + 2;
    if (*puVar10 < *param_3) break;
    iVar1 = (uint)uVar3 * 0x40 + *(int *)(param_1 + 0x3c);
    if ((*param_3 & 1) == 0) {
      psVar2 = (short *)(iVar1 + 0x30 + param_2 * 2);
      *psVar2 = *psVar2 + -1;
    }
    else {
      iVar11 = (uint)puVar10[1] * 0x40 + *(int *)(param_1 + 0x3c);
      uVar8 = 1 << ((byte)param_2 & 0x1f) & 3;
      uVar9 = 1 << (sbyte)uVar8 & 3;
      if ((((param_5 != '\0') &&
           (*(ushort *)(iVar1 + 0x30 + uVar8 * 2) <= *(ushort *)(iVar11 + 0x36 + uVar8 * 2))) &&
          (*(ushort *)(iVar11 + 0x30 + uVar8 * 2) <= *(ushort *)(iVar1 + 0x36 + uVar8 * 2))) &&
         ((*(ushort *)(iVar1 + 0x30 + uVar9 * 2) <= *(ushort *)(iVar11 + 0x36 + uVar9 * 2) &&
          (*(ushort *)(iVar11 + 0x30 + uVar9 * 2) <= *(ushort *)(iVar1 + 0x36 + uVar9 * 2))))) {
        (**(code **)(**(int **)(param_1 + 0x5c) + 8))(iVar11,iVar1,param_4);
        if (*(int **)(param_1 + 0x60) != (int *)0x0) {
          (**(code **)(**(int **)(param_1 + 0x60) + 8))(iVar11,iVar1,param_4);
        }
      }
      psVar2 = (short *)(iVar1 + 0x36 + param_2 * 2);
      *psVar2 = *psVar2 + -1;
    }
    psVar2 = (short *)((uint)uVar4 * 0x40 + iVar5 + 0x30 + param_2 * 2);
    *psVar2 = *psVar2 + 1;
    uVar6 = *(undefined4 *)puVar10;
    *(undefined4 *)puVar10 = *(undefined4 *)param_3;
    *(undefined4 *)param_3 = uVar6;
    uVar3 = puVar7[5];
    puVar10 = puVar10 + 2;
    puVar7 = param_3;
  }
  return;
}

