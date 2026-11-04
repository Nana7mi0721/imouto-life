
void FUN_00649030(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,ushort *param_9)

{
  ushort *puVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  undefined4 *puVar9;
  
  uVar4 = *(ushort *)(param_1 + 0x1a);
  if (param_6 != 0) {
    puVar8 = param_9;
    do {
      if (param_5 != 0) {
        puVar9 = param_2;
        param_9 = (ushort *)param_5;
        while( true ) {
          iVar6 = *(int *)(param_1 + 0x50);
          puVar1 = puVar8 + 3;
          param_2 = puVar9 + 1;
          puVar2 = puVar8 + 2;
          iVar7 = (uint)*(byte *)((uint)*puVar1 + iVar6) * 0x100 + *(int *)(param_1 + 0x4c);
          puVar3 = puVar8 + 1;
          uVar5 = *puVar8;
          puVar8 = puVar8 + uVar4;
          *puVar9 = CONCAT31(CONCAT21(CONCAT11(*(byte *)((uint)*puVar1 + iVar6),
                                               *(undefined1 *)
                                                ((uint)*(byte *)((uint)*puVar2 + iVar6) + iVar7)),
                                      *(undefined1 *)
                                       ((uint)*(byte *)((uint)*puVar3 + iVar6) + iVar7)),
                             *(undefined1 *)((uint)*(byte *)((uint)uVar5 + iVar6) + iVar7));
          param_9 = (ushort *)((int)param_9 + -1);
          if (param_9 == (ushort *)0x0) break;
          puVar9 = param_2;
        }
      }
      puVar8 = puVar8 + (uint)uVar4 * param_7;
      param_2 = param_2 + param_8;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  return;
}

