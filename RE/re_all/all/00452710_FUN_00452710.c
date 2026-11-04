
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __fastcall FUN_00452710(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> abStack_c4 [20];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined *puStack_94;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *pbStack_90;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_7c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> local_58 [28];
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *local_3c;
  undefined1 *local_38;
  undefined1 *local_34;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> local_30 [28];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad9dc;
  local_10 = ExceptionList;
  local_14 = DAT_0084b484;
  pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               &DAT_00a13fc0;
  puStack_94 = (undefined *)0x45274c;
  ExceptionList = &local_10;
  cVar2 = operator!=<>();
  if (cVar2 == '\0') {
    pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                 &DAT_00a14014;
    puStack_94 = (undefined *)0x452765;
    cVar2 = operator!=<>();
    if (cVar2 == '\0') {
      pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   &DAT_00a18b6c;
      puStack_94 = &DAT_00a18b50;
      uStack_98 = 1;
      uStack_9c = 0;
      uStack_a0 = *(undefined4 *)(param_1 + 0x10);
      uStack_a4 = *(undefined4 *)(param_1 + 0x18);
      uStack_ac = 0;
      uStack_b0 = 0x4527ae;
      pbVar3 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
               FUN_004cc4c0();
      local_34 = abStack_c4;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>(abStack_c4,pbVar3);
      FUN_00424670();
      local_8 = 0;
      pbStack_90 = local_30;
      puStack_94 = (undefined *)0x4527e3;
      cVar2 = FUN_004ec750();
      if (cVar2 == '\0') {
        local_7c = local_30;
      }
      else {
        pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )0x4527fa;
        local_7c = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   basic_string<>();
        local_8 = CONCAT31(local_8._1_3_,1);
      }
      local_3c = local_7c;
      local_38 = (undefined1 *)&uStack_a4;
      uStack_ac = 0x452835;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&uStack_a4,
                 local_7c);
      FUN_004526a0();
      local_8 = 0;
      if (cVar2 != '\0') {
        std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
        ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(local_58);
      }
      pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   0x452869;
      FUN_004cb840();
      pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   0x452878;
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
                ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)&DAT_00a13fdc,""
                );
      DAT_00a140b9 = 0;
      uVar4 = FUN_004e5650();
      if (uVar4 < 2) {
        *(undefined1 *)(param_1 + 0x850) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x850) = 0;
      }
      pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   (*(int *)(param_1 + 8) + 1);
      puStack_94 = (undefined *)0x4528be;
      FUN_004cecd0();
      pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *)
                   0x4528c5;
      piVar5 = (int *)FUN_004ce990();
      if (*piVar5 == 0x66) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
        _DAT_00a14034 = 0;
        DAT_00a14090 = 1;
        DAT_00a14091 = 0;
        pbStack_90 = (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )0x452906;
        uVar6 = FUN_004cecd0();
        FUN_00487300(uVar6);
        cVar2 = FUN_00450200();
        if (cVar2 == '\0') {
          DAT_00a14090 = 0;
        }
      }
      uVar1 = *(undefined1 *)(param_1 + 0x850);
      local_8 = 0xffffffff;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_30);
      ExceptionList = local_10;
      return uVar1;
    }
  }
  ExceptionList = local_10;
  return 0;
}

