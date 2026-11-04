
void FUN_00581fb0(int param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_18 = *(int *)(param_1 + 4);
  if (param_2 == (int *)0x0) {
    local_14 = *(int *)(param_1 + 8);
    local_20 = 0;
    local_1c = 0;
  }
  else {
    local_4 = *(undefined4 *)(param_1 + 8);
    local_20 = *param_2;
    local_1c = param_2[1];
    local_14 = param_2[3];
    local_10 = 0;
    local_c = 0;
    local_8 = local_18;
    local_18 = param_2[2];
    FUN_00514e10(&local_20,&local_10);
  }
  local_14 = local_14 - local_1c;
  local_18 = local_18 - local_20;
  uVar3 = (uint)*(byte *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 4);
  iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  puVar2 = (undefined4 *)(iVar5 * local_1c + uVar3 * local_20 + *(int *)(param_1 + 0xc));
  iVar5 = iVar5 - uVar3 * local_18;
  if ((local_18 != 0) && (local_14 != 0)) {
    cVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x14) + 0x14) + 4);
    if (cVar1 == '\x01') {
      param_1 = local_14;
      do {
        iVar4 = local_18;
        do {
          *(undefined1 *)puVar2 = (undefined1)param_3;
          puVar2 = (undefined4 *)((int)puVar2 + 1);
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        puVar2 = (undefined4 *)((int)puVar2 + iVar5);
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    else {
      if (cVar1 == '\x02') {
        do {
          iVar4 = local_18;
          do {
            *(short *)puVar2 = (short)param_3;
            puVar2 = (undefined4 *)((int)puVar2 + 2);
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          puVar2 = (undefined4 *)((int)puVar2 + iVar5);
          local_14 = local_14 + -1;
        } while (local_14 != 0);
        return;
      }
      if (cVar1 == '\x04') {
        do {
          iVar4 = local_18;
          do {
            *puVar2 = param_3;
            puVar2 = puVar2 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          puVar2 = (undefined4 *)((int)puVar2 + iVar5);
          local_14 = local_14 + -1;
        } while (local_14 != 0);
        return;
      }
    }
  }
  return;
}

