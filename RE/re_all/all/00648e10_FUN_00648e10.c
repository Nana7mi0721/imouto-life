
void FUN_00648e10(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,byte *param_9)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x1a);
  for (; iVar2 = param_5, param_6 != 0; param_6 = param_6 + -1) {
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      iVar3 = (uint)param_9[3] * 0x100 + *(int *)(param_1 + 0x4c);
      *param_2 = CONCAT31(CONCAT21(CONCAT11(param_9[3],*(undefined1 *)((uint)param_9[2] + iVar3)),
                                   *(undefined1 *)((uint)param_9[1] + iVar3)),
                          *(undefined1 *)((uint)*param_9 + iVar3));
      param_9 = param_9 + uVar1;
      param_2 = param_2 + 1;
    }
    param_9 = param_9 + (uint)uVar1 * param_7;
    param_2 = param_2 + param_8;
  }
  return;
}

