
void __thiscall
FUN_00795ee0(int param_1,int *param_2,ushort *param_3,ushort *param_4,int param_5,int param_6)

{
  ushort *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  
  iVar4 = 0;
  puVar5 = (ushort *)(*(int *)(param_1 + 0x88) + param_5 * 0x10);
joined_r0x00795eff:
  do {
    if (param_6 <= param_5) {
      if (DAT_00f488d8 < iVar4) {
        DAT_00f488d8 = iVar4;
      }
      return;
    }
    iVar4 = iVar4 + 1;
    uVar3 = (uint)(((((param_3[2] <= puVar5[5] && param_3[1] <= puVar5[4]) &&
                     puVar5[2] <= param_4[2]) && puVar5[1] <= param_4[1]) && *param_3 <= puVar5[3])
                  && *puVar5 <= *param_4);
    uVar2 = *(uint *)(puVar5 + 6);
    uVar3 = (int)(-uVar3 | uVar3) >> 0x1f & 1;
    if ((int)uVar2 < 0) {
LAB_00795fa0:
      if (uVar3 == 0) goto LAB_00795fa4;
    }
    else {
      if (uVar3 != 0) {
        (**(code **)(*param_2 + 4))((int)uVar2 >> 0x15,uVar2 & 0x1fffff);
        goto LAB_00795fa0;
      }
LAB_00795fa4:
      if ((int)uVar2 < 0) {
        puVar1 = puVar5 + 6;
        puVar5 = puVar5 + *(int *)puVar1 * -8;
        param_5 = param_5 - *(int *)puVar1;
        goto joined_r0x00795eff;
      }
    }
    puVar5 = puVar5 + 8;
    param_5 = param_5 + 1;
  } while( true );
}

