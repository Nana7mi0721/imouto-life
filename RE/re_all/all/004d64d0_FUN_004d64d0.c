
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void __thiscall
FUN_004d64d0(void *param_1,int param_2,uint param_3,
            basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_52 [6];
  uint local_4c;
  uint local_38;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  undefined1 *local_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b11b8;
  pvStack_10 = ExceptionList;
  local_18 = DAT_0084b484;
  local_14 = auStack_52 + -0xe;
  ExceptionList = &pvStack_10;
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>(local_34,param_4);
  local_8 = 0;
  local_4c = FUN_004d6230();
  if (param_3 != 0) {
    iVar1 = FUN_004cc430();
    iVar2 = FUN_004e1fe0();
    if ((uint)(iVar2 - iVar1) < param_3) {
      FID_conflict__Xran(param_1);
    }
    else {
      iVar1 = FUN_004cc430();
      if (local_4c < iVar1 + param_3) {
        iVar1 = FUN_004e1fe0();
        if (iVar1 - (local_4c >> 1) < local_4c) {
          local_4c = 0;
        }
        else {
          local_4c = (local_4c >> 1) + local_4c;
        }
        local_38 = local_4c;
        iVar1 = FUN_004cc430();
        if (local_4c < iVar1 + param_3) {
          iVar1 = FUN_004cc430();
          local_38 = iVar1 + param_3;
        }
        iVar1 = FUN_004e0e20(local_38);
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = DoMessageBox(*(undefined4 *)((int)param_1 + 4),param_2,iVar1);
        uVar3 = FUN_004d6820(uVar3,param_3,local_34);
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),uVar3);
        local_8 = 0;
        iVar2 = FUN_004cc430();
        if (*(int *)((int)param_1 + 4) != 0) {
          FUN_004d6430(*(undefined4 *)((int)param_1 + 4),*(undefined4 *)((int)param_1 + 8));
          deallocate(*(undefined4 *)((int)param_1 + 4),
                     (*(int *)((int)param_1 + 0xc) - *(int *)((int)param_1 + 4)) / 0x1c);
        }
        *(uint *)((int)param_1 + 0xc) = local_38 * 0x1c + iVar1;
        *(uint *)((int)param_1 + 8) = (iVar2 + param_3) * 0x1c + iVar1;
        *(int *)((int)param_1 + 4) = iVar1;
      }
      else if ((uint)((*(int *)((int)param_1 + 8) - param_2) / 0x1c) < param_3) {
        DoMessageBox(param_2,*(undefined4 *)((int)param_1 + 8),param_3 * 0x1c + param_2);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_004d6820(*(undefined4 *)((int)param_1 + 8),
                     param_3 - (*(int *)((int)param_1 + 8) - param_2) / 0x1c,local_34);
        local_8 = 0;
        *(uint *)((int)param_1 + 8) = param_3 * 0x1c + *(int *)((int)param_1 + 8);
        _Destroy_range<>(param_2,*(int *)((int)param_1 + 8) + param_3 * -0x1c,local_34);
      }
      else {
        iVar1 = *(int *)((int)param_1 + 8);
        uVar3 = DoMessageBox(iVar1 + param_3 * -0x1c,iVar1,*(undefined4 *)((int)param_1 + 8));
        *(undefined4 *)((int)param_1 + 8) = uVar3;
        FUN_004eda90(param_2,iVar1 + param_3 * -0x1c,iVar1);
        _Destroy_range<>(param_2,param_3 * 0x1c + param_2,local_34);
      }
    }
  }
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
            ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)local_34);
  ExceptionList = pvStack_10;
  return;
}

