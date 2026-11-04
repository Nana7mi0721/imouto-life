
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004b5c50(int param_1,uint param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> *this;
  int *piVar4;
  int local_22c;
  int local_228;
  int local_224;
  char local_220 [256];
  char local_120 [260];
  undefined4 local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007b061c;
  local_10 = ExceptionList;
  local_1c = DAT_0084b484;
  ExceptionList = &local_10;
  iVar1 = FUN_004d00e0();
  if (param_1 < iVar1) {
    FUN_004d0120();
    iVar1 = FUN_004cfc90();
    if ((((int)param_2 < iVar1) && (-1 < param_1)) && (param_2 < 0x80000000)) {
      FUN_004d0120();
      FUN_004cfcd0();
      local_14 = FUN_004ce080();
      FUN_004d0120();
      FUN_004cfcd0();
      local_18 = FUN_004cc430();
      for (local_224 = 0; local_224 < local_14; local_224 = local_224 + 1) {
        FUN_004d0120();
        FUN_004cfcd0();
        puVar3 = (undefined4 *)FUN_004ce990();
        *puVar3 = 0;
      }
      for (local_228 = 0; local_228 < local_18; local_228 = local_228 + 1) {
        pcVar2 = "";
        FUN_004d0120();
        FUN_004cfcd0();
        this = (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)FUN_004cc4c0();
        std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator=(this,pcVar2)
        ;
      }
      for (local_22c = 0; local_22c < local_14 + local_18; local_22c = local_22c + 1) {
        FUN_004d0120();
        piVar4 = (int *)FUN_004ce990();
        if (*piVar4 / 1000 == 1) {
          FUN_004d05c0();
          iVar1 = FUN_004ce080();
          if (local_22c < iVar1) {
            FUN_004d05c0();
            FUN_004ce990();
            FUN_00477f90();
          }
        }
      }
      ExceptionList = local_10;
      return;
    }
  }
  iVar1 = FUN_004d00e0();
  if (iVar1 <= param_1) {
    basic_string<>();
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_120,pcVar2);
    basic_string<>();
    local_8 = 0;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,1);
    basic_string<>(local_120);
    local_8 = 0xffffffff;
    FUN_0042bed0();
  }
  if (0x7fffffff < param_2) {
    basic_string<>();
    pcVar2 = (char *)FUN_00401c50();
    _sprintf(local_220,pcVar2);
    basic_string<>();
    local_8 = 2;
    FUN_00438b60();
    local_8 = CONCAT31(local_8._1_3_,3);
    basic_string<>(local_220);
    local_8 = 0xffffffff;
    FUN_0042bed0();
  }
  ExceptionList = local_10;
  return;
}

