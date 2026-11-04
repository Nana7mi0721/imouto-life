
void __thiscall FUN_004da1e0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_52 [6];
  uint local_4c;
  uint local_38;
  undefined1 local_34 [32];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b13a8;
  pvStack_10 = ExceptionList;
  local_14 = auStack_52 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004da510(param_4);
  local_8 = 0;
  local_4c = FUN_004d9f40();
  if (param_3 != 0) {
    iVar1 = FUN_004cfc90();
    iVar2 = FUN_004e4a00();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cfc90();
      if (local_4c < iVar1 + param_3) {
        iVar1 = FUN_004e4a00();
        if (iVar1 - (local_4c >> 1) < local_4c) {
          local_4c = 0;
        }
        else {
          local_4c = (local_4c >> 1) + local_4c;
        }
        local_38 = local_4c;
        iVar1 = FUN_004cfc90();
        if (local_4c < iVar1 + param_3) {
          iVar1 = FUN_004cfc90();
          local_38 = iVar1 + param_3;
        }
        iVar1 = FUN_004e4a20(local_38);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004da570(uVar3,param_3,local_34);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004cfc90();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004da140(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     *(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4) >> 5);
        }
        *(uint *)((int)param_1 + 0xc) = local_38 * 0x20 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x20 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)(*(int *)((int)param_1 + 8) - param_2 >> 5) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x20 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004da570(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2 >> 5),local_34);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x20 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x20,local_34);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x20,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee130(param_2,iVar1 + param_3 * -0x20,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x20 + param_2,local_34);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_00477f40();
  ExceptionList = pvStack_10;
  return;
}

