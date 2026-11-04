
undefined4 * __fastcall FUN_004441f0(undefined4 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007ad64b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00440ae0();
  local_8 = 0;
  *param_1 = &PTR_FUN_007d0aa8;
  FUN_004d2320();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00440e60();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)(param_1 + 2),"");
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(undefined1 *)((int)param_1 + 0xba) = 1;
  puVar1 = (undefined1 *)FUN_004cd7c0(0);
  *puVar1 = DAT_00a18ab4;
  *(undefined2 *)(param_1 + 0x2f) = 0xffff;
  *(undefined1 *)(param_1 + 0x30) = 0;
  FUN_004ce950();
  FUN_004ce660();
  *(undefined1 *)(param_1 + 0x52) = 0;
  *(undefined1 *)((int)param_1 + 0x149) = 0;
  param_1[0x53] = 0;
  FUN_004d25b0(DAT_0084b21c);
  for (local_14 = 0; local_14 < DAT_0084b21c; local_14 = local_14 + 1) {
    iVar2 = FUN_004d2620(local_14);
    *(undefined1 *)(iVar2 + 0x53) = 1;
    iVar2 = FUN_004d2620(local_14);
    *(undefined1 *)(iVar2 + 0xbf) = 1;
    iVar2 = FUN_004d2620(local_14);
    *(int *)(iVar2 + 0x24) = -3 - local_14;
  }
  ExceptionList = local_10;
  return param_1;
}

