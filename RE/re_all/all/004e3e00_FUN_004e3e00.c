
void __thiscall FUN_004e3e00(void *param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_4a [6];
  uint local_44;
  uint local_30;
  CDHtmlElementEventSink local_2c [24];
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b1798;
  pvStack_10 = ExceptionList;
  local_14 = auStack_4a + -0xe;
  ExceptionList = &pvStack_10;
  FUN_004a5960(param_4);
  local_8 = 0;
  local_44 = FUN_004ea830();
  if (param_3 != 0) {
    iVar1 = FUN_004ce7d0();
    iVar2 = FUN_004e3d40();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004ce7d0();
      if (local_44 < iVar1 + param_3) {
        iVar1 = FUN_004e3d40();
        if (iVar1 - (local_44 >> 1) < local_44) {
          local_44 = 0;
        }
        else {
          local_44 = (local_44 >> 1) + local_44;
        }
        local_30 = local_44;
        iVar1 = FUN_004ce7d0();
        if (local_44 < iVar1 + param_3) {
          iVar1 = FUN_004ce7d0();
          local_30 = iVar1 + param_3;
        }
        iVar1 = FUN_004e4140(local_30);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004ea870(uVar3,param_3,local_2c);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004ce7d0();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004e3dd0(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x18);
        }
        *(uint *)((int)param_1 + 0xc) = local_30 * 0x18 + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x18 + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x18) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x18 + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004ea870(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x18,local_2c);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x18 + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x18,local_2c);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x18,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eeb30(param_2,iVar1 + param_3 * -0x18,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x18 + param_2,local_2c);
      }
    }
  }
  local_8 = 0xffffffff;
  CDHtmlElementEventSink::~CDHtmlElementEventSink(local_2c);
  ExceptionList = pvStack_10;
  return;
}

