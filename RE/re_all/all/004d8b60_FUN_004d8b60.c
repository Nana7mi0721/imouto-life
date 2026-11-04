
void __thiscall FUN_004d8b60(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_8a [6];
  uint local_84;
  uint local_70;
  CBitmapButton local_6c [88];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1308;
  pvStack_10 = ExceptionList;
  local_14 = auStack_8a + -0xe;
  ExceptionList = &pvStack_10;
  FUN_00487300(param_4);
  local_8 = 0;
  local_84 = FUN_004d8930();
  if (param_3 != 0) {
    iVar1 = FUN_004cec90();
    iVar2 = FUN_004e41b0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cec90();
      if (local_84 < iVar1 + param_3) {
        iVar1 = FUN_004e41b0();
        if (iVar1 - (local_84 >> 1) < local_84) {
          local_84 = 0;
        }
        else {
          local_84 = (local_84 >> 1) + local_84;
        }
        local_70 = local_84;
        iVar1 = FUN_004cec90();
        if (local_84 < iVar1 + param_3) {
          iVar1 = FUN_004cec90();
          local_70 = iVar1 + param_3;
        }
        iVar1 = FUN_004e4240(local_70);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004d8eb0(uVar3,param_3,local_6c);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004cec90();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d8ac0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x54);
        }
        *(uint *)((int)param_1 + 0xc) = local_70 * 0x54 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x54 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x54) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x54 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004d8eb0(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x54,local_6c);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x54 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x54,local_6c);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x54,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004edd70(param_2,iVar1 + param_3 * -0x54,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x54 + param_2,local_6c);
      }
    }
  }
  local_8 = 0xffffffff;
  CBitmapButton::~CBitmapButton(local_6c);
  ExceptionList = pvStack_10;
  return;
}

