
void __thiscall FUN_004e31f0(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_42 [6];
  uint local_3c;
  uint local_28;
  undefined1 local_24 [16];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1738;
  pvStack_10 = ExceptionList;
  local_14 = auStack_42 + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004cd0c0(param_4);
  local_8 = 0;
  local_3c = FUN_004d7a70();
  if (param_3 != 0) {
    iVar1 = FUN_004cd340();
    iVar2 = FUN_004e26e0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cd340();
      if (local_3c < iVar1 + param_3) {
        iVar1 = FUN_004e26e0();
        if (iVar1 - (local_3c >> 1) < local_3c) {
          local_3c = 0;
        }
        else {
          local_3c = (local_3c >> 1) + local_3c;
        }
        local_28 = local_3c;
        iVar1 = FUN_004cd340();
        if (local_3c < iVar1 + param_3) {
          iVar1 = FUN_004cd340();
          local_28 = iVar1 + param_3;
        }
        iVar1 = FUN_004e38c0(local_28);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004ea770(uVar3,param_3,local_24);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004cd340();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d80b0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     *(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4) >> 4);
        }
        *(uint *)((int)param_1 + 0xc) = local_28 * 0x10 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x10 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)(*(int *)((int)param_1 + 8) - param_2 >> 4) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x10 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004ea770(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2 >> 4),local_24);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x10 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x10,local_24);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x10,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004ee910(param_2,iVar1 + param_3 * -0x10,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x10 + param_2,local_24);
      }
    }
  }
  local_8 = 0xffffffff;
  FUN_004cd4c0();
  ExceptionList = pvStack_10;
  return;
}

