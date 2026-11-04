
void FUN_0064d9f0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,byte *param_9,byte *param_10,byte *param_11,
                 byte *param_12)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_4;
  
  if (param_6 != 0) {
    local_4 = param_6;
    do {
      if (param_5 != 0) {
        puVar6 = param_2;
        param_6 = param_5;
        do {
          param_2 = puVar6 + 1;
          bVar1 = *param_12;
          param_12 = param_12 + 1;
          bVar2 = *param_9;
          iVar5 = (uint)bVar1 * 0x100 + *(int *)(param_1 + 0x4c);
          bVar3 = *param_10;
          param_9 = param_9 + 1;
          param_10 = param_10 + 1;
          bVar4 = *param_11;
          param_11 = param_11 + 1;
          *puVar6 = CONCAT31(CONCAT21(CONCAT11(bVar1,*(undefined1 *)((uint)bVar4 + iVar5)),
                                      *(undefined1 *)((uint)bVar3 + iVar5)),
                             *(undefined1 *)((uint)bVar2 + iVar5));
          param_6 = param_6 + -1;
          puVar6 = param_2;
        } while (param_6 != 0);
      }
      param_11 = param_11 + param_7;
      param_9 = param_9 + param_7;
      param_10 = param_10 + param_7;
      param_12 = param_12 + param_7;
      param_2 = param_2 + param_8;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
  }
  return;
}

