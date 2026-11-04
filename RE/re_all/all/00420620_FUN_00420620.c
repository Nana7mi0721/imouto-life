
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined1
FUN_00420620(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_1)

{
  char cVar1;
  char *pcVar2;
  FILE *_File;
  size_t sVar3;
  void *pvVar4;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000020;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack0000003c;
  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> bStack00000058;
  char *pcVar5;
  FILE *local_48;
  int local_44;
  undefined2 local_3c;
  undefined2 local_3a;
  undefined1 local_38;
  undefined4 local_34;
  size_t local_30 [7];
  void *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_007ac22e;
  local_10 = ExceptionList;
  local_34 = DAT_0084b484;
  local_8 = 3;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_14 = (void *)0x0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  pcVar5 = "wb";
  ExceptionList = &local_10;
  pcVar2 = (char *)FUN_004cbb30();
  _File = _fopen(pcVar2,pcVar5);
  local_14 = _malloc(0x4c4b41);
  for (local_44 = 0; local_44 < 3; local_44 = local_44 + 1) {
    if ((local_44 == 0) && (cVar1 = operator!=<>(&bStack00000020,&DAT_007cc58b), cVar1 != '\0')) {
      pcVar5 = "rb";
      pcVar2 = (char *)FUN_004cbb30();
      local_48 = _fopen(pcVar2,pcVar5);
    }
    if ((local_44 == 1) && (cVar1 = operator!=<>(&bStack0000003c,&DAT_007cc58f), cVar1 != '\0')) {
      pcVar5 = "rb";
      pcVar2 = (char *)FUN_004cbb30();
      local_48 = _fopen(pcVar2,pcVar5);
    }
    if ((local_44 == 2) && (cVar1 = operator!=<>(&bStack00000058,&DAT_007cc593), cVar1 != '\0')) {
      pcVar5 = "rb";
      pcVar2 = (char *)FUN_004cbb30();
      local_48 = _fopen(pcVar2,pcVar5);
    }
    if (local_48 != (FILE *)0x0) {
      _fseek(local_48,0,2);
      sVar3 = _ftell(local_48);
      local_30[local_44] = sVar3;
      _fseek(local_48,0,0);
      pvVar4 = _malloc(local_30[local_44] + 1);
      local_30[local_44 + 4] = (size_t)pvVar4;
      _fread((void *)local_30[local_44 + 4],1,local_30[local_44],local_48);
      _fclose(local_48);
      _fwrite((void *)local_30[local_44 + 4],1,local_30[local_44],_File);
      _free((void *)local_30[local_44 + 4]);
    }
  }
  local_3c = DAT_007cc598;
  local_3a = 0;
  local_38 = 0;
  _fwrite(&local_3c,1,1,_File);
  _fclose(_File);
  _free(local_14);
  local_8._0_1_ = 2;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_1);
  local_8._0_1_ = 1;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000020);
  local_8 = (uint)local_8._1_3_ << 8;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack0000003c);
  local_8 = 0xffffffff;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&bStack00000058);
  ExceptionList = local_10;
  return 1;
}

