
void __thiscall FUN_004e2ac0(allocator<char> *param_1,int param_2,uint param_3,undefined1 *param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 auStack_36 [6];
  uint local_30;
  uint local_1c;
  undefined1 local_15;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b17d0;
  pvStack_10 = ExceptionList;
  local_14 = auStack_36 + -0xe;
  local_15 = *param_4;
  ExceptionList = &pvStack_10;
  local_30 = FUN_004d9b70();
  if (param_3 != 0) {
    iVar1 = FUN_004cd730();
    iVar2 = FUN_004e2aa0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cd730();
      if (local_30 < iVar1 + param_3) {
        iVar1 = FUN_004e2aa0();
        if (iVar1 - (local_30 >> 1) < local_30) {
          local_30 = 0;
        }
        else {
          local_30 = (local_30 >> 1) + local_30;
        }
        local_1c = local_30;
        iVar1 = FUN_004cd730();
        if (local_30 < iVar1 + param_3) {
          iVar1 = FUN_004cd730();
          local_1c = iVar1 + param_3;
        }
        pcVar3 = std::allocator<char>::allocate(param_1,local_1c);
        local_8 = 0;
        uVar4 = DoMessageBox(*(undefined4 *)(param_1 + 4),param_2,pcVar3);
        uVar4 = FUN_004ea9a0(uVar4,param_3,&local_15);
        DoMessageBox(param_2,*(undefined4 *)(param_1 + 8),uVar4);
        local_8 = 0xffffffff;
        iVar1 = FUN_004cd730();
        if (*(int *)(param_1 + 4) != 0) {
          FUN_004e4160(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8));
          deallocate(*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0xc) - *(int *)(param_1 + 4));
        }
        *(char **)(param_1 + 0xc) = pcVar3 + local_1c;
        *(char **)(param_1 + 8) = pcVar3 + iVar1 + param_3;
        *(char **)(param_1 + 4) = pcVar3;
      }
      else if ((uint)(*(int *)(param_1 + 8) - param_2) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)(param_1 + 8),param_2 + param_3);
        local_8 = 2;
        FUN_004ea9a0(*(undefined4 *)(param_1 + 8),param_3 - (*(int *)(param_1 + 8) - param_2),
                     &local_15);
        local_8 = 0xffffffff;
        *(uint *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;
        FUN_004eebf0(param_2,*(int *)(param_1 + 8) - param_3,&local_15);
      }
      else {
        iVar1 = *(int *)(param_1 + 8);
        uVar4 = DoMessageBox(iVar1 - param_3,iVar1,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)(param_1 + 8) = uVar4;
        FUN_004ee840(param_2,iVar1 - param_3,iVar1);
        FUN_004eebf0(param_2,param_2 + param_3,&local_15);
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}

