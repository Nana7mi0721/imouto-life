
/* WARNING: Function: __SEH_prolog replaced with injection: SEH_prolog */
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* Library Function - Single Match
    ___security_error_handler
   
   Library: Visual Studio 2003 Release */

void ___security_error_handler(int param_1)

{
  code *pcVar1;
  DWORD DVar2;
  size_t sVar3;
  char *_Str;
  char acStack_156 [14];
  undefined4 local_12c;
  CHAR local_128 [260];
  undefined1 local_24;
  undefined4 local_20;
  undefined1 *local_1c;
  undefined4 uStack_c;
  undefined *local_8;
  
  local_8 = &DAT_007d29c8;
  uStack_c = 0x501664;
  local_20 = DAT_0084b484;
  if (DAT_00a1fc54 == (code *)0x0) {
    if (param_1 == 1) {
      local_12c = 
      "A buffer overrun has been detected which has corrupted the program\'s\ninternal state.  The program cannot safely continue execution and must\nnow be terminated.\n"
      ;
    }
    else {
      local_12c = 
      "A security error of unknown cause has been detected which has\ncorrupted the program\'s internal state.  The program cannot safely\ncontinue execution and must now be terminated.\n"
      ;
    }
    local_24 = 0;
    DVar2 = GetModuleFileNameA((HMODULE)0x0,local_128,0x104);
    if (DVar2 == 0) {
      FUN_004fd700();
    }
    _Str = local_128;
    sVar3 = _strlen(_Str);
    if (0x3c < sVar3 + 0xb) {
      sVar3 = _strlen(_Str);
      _Str = acStack_156 + (sVar3 - 3);
      _strncpy(_Str,"...",3);
    }
    _strlen(_Str);
    local_1c = local_128 + -0x10;
    FUN_004fd700();
    FUN_004fd710();
    FUN_004fd710();
    FUN_004fd710();
    FUN_004fd710(local_128 + -0x10,&DAT_007d1be8);
    FUN_004fd710(local_128 + -0x10,local_12c);
    ___crtMessageBoxA(local_128 + -0x10,"Microsoft Visual C++ Runtime Library",0x12010);
  }
  else {
    local_8 = (undefined *)0x0;
    (*DAT_00a1fc54)();
    local_8 = (undefined *)0xffffffff;
  }
  __exit();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

