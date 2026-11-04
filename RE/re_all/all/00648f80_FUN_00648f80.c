
void FUN_00648f80(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,ushort *param_9)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort *puVar4;
  
  puVar4 = param_9;
  uVar1 = *(ushort *)(param_1 + 0x1a);
  if (param_6 != 0) {
    param_9 = (ushort *)param_6;
    iVar3 = param_5;
    do {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        iVar2 = *(int *)(param_1 + 0x50);
        *param_2 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)((uint)puVar4[3] + iVar2),
                                              *(undefined1 *)((uint)puVar4[2] + iVar2)),
                                     *(undefined1 *)((uint)puVar4[1] + iVar2)),
                            *(undefined1 *)((uint)*puVar4 + iVar2));
        puVar4 = puVar4 + uVar1;
        param_2 = param_2 + 1;
      }
      puVar4 = puVar4 + (uint)uVar1 * param_7;
      param_2 = param_2 + param_8;
      param_9 = (ushort *)((int)param_9 + -1);
      iVar3 = param_5;
    } while (param_9 != (ushort *)0x0);
  }
  return;
}

