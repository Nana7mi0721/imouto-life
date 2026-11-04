
int FUN_004b66a0(char *param_1,undefined4 param_2,int param_3,int param_4,char param_5)

{
  size_t sVar1;
  char *_Str;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_1c4;
  int local_1c0;
  int local_1b8;
  int local_1ac;
  int local_1a4;
  int local_1a0;
  int aiStack_19c [100];
  int local_c;
  int local_8;
  
  local_1a0 = 0;
  sVar1 = _strlen(param_1);
  _Str = _malloc(sVar1 * 2 + 100);
  iVar2 = FUN_00477980();
  for (local_1b8 = 0; local_1b8 < iVar2; local_1b8 = local_1b8 + 1) {
    FUN_004d0120();
    piVar3 = (int *)FUN_004ce990();
    aiStack_19c[local_1b8] = *piVar3 / 1000;
  }
  local_c = -1;
  while (((local_1a0 < (int)sVar1 && (param_1[local_1a0] != '\0')) && (local_c == -1))) {
    if (param_1[local_1a0] == '\n') {
      local_c = 0;
    }
    local_1a0 = local_1a0 + 1;
  }
  local_1ac = param_3;
  local_8 = 0;
  local_1a4 = 0;
  for (; (local_1a0 < (int)sVar1 && (param_1[local_1a0] != '\0')); local_1a0 = local_1a0 + 1) {
    switch(param_1[local_1a0]) {
    case '\x01':
      iVar4 = param_1[local_1a0 + 1] + 1;
      if (param_5 != '\0') {
        if (local_c == 0) {
          local_c = 2;
          for (local_1c0 = 0; local_1c0 < iVar4; local_1c0 = local_1c0 + 1) {
            _Str[local_1a4] = param_1[local_1a0 + local_1c0];
            local_1a4 = local_1a4 + 1;
          }
        }
        else if ((0 < local_c) && (local_c < 3)) {
          for (local_1c4 = 0; local_1c4 < iVar4; local_1c4 = local_1c4 + 1) {
            _Str[local_1a4] = param_1[local_1a0 + local_1c4];
            local_1a4 = local_1a4 + 1;
          }
        }
      }
      local_1a0 = local_1a0 + -1 + iVar4;
      break;
    default:
      if (param_5 != '\0') {
        if (local_c == 0) {
          local_c = 2;
          _Str[local_1a4] = param_1[local_1a0];
          local_1a4 = local_1a4 + 1;
        }
        else if ((0 < local_c) && (local_c < 3)) {
          _Str[local_1a4] = param_1[local_1a0];
          local_1a4 = local_1a4 + 1;
        }
      }
      break;
    case '\n':
      switch(local_c) {
      case 1:
        if (param_5 != '\0') {
          _Str[local_1a4] = '\r';
          _Str[local_1a4 + 1] = '\n';
          local_1a4 = local_1a4 + 2;
        }
        break;
      case 2:
        if ((param_5 != '\0') && (_Str[local_1a4] = '\0', local_8 < iVar2)) {
          if (aiStack_19c[local_8] == 1) {
            _atol(_Str);
            FUN_00477f90();
          }
          else if (aiStack_19c[local_8] == 2) {
            basic_string<>(_Str);
            FUN_00478010(param_2,local_1ac,local_8);
          }
        }
      case 0:
      case 3:
        local_1a4 = 0;
        local_1ac = local_1ac + 1;
        if (param_4 <= local_1ac - param_3) {
          _free(_Str);
          return local_1ac - param_3;
        }
        local_8 = 0;
        local_c = 0;
      }
      break;
    case '\r':
      break;
    case '\"':
      if (local_c == 0) {
        local_c = 1;
      }
      else if (local_c == 1) {
        if (param_1[local_1a0 + 1] == '\"') {
          if (param_1[local_1a0 + 1] == '\"') {
            _Str[local_1a4] = '\"';
            local_1a0 = local_1a0 + 1;
            local_1a4 = local_1a4 + 1;
          }
        }
        else {
          if (param_5 != '\0') {
            _Str[local_1a4] = '\0';
            if (local_8 < iVar2) {
              if (aiStack_19c[local_8] == 1) {
                _atol(_Str);
                FUN_00477f90();
              }
              else if (aiStack_19c[local_8] == 2) {
                basic_string<>(_Str);
                FUN_00478010(param_2,local_1ac,local_8);
              }
            }
            local_1a4 = 0;
          }
          local_c = 3;
        }
      }
      break;
    case ',':
      switch(local_c) {
      case 0:
        if (param_5 != '\0') {
          _Str[local_1a4] = '\0';
          if (local_8 < iVar2) {
            if (aiStack_19c[local_8] == 1) {
              _atol(_Str);
              FUN_00477f90();
            }
            else if (aiStack_19c[local_8] == 2) {
              basic_string<>(_Str);
              FUN_00478010(param_2,local_1ac,local_8);
            }
          }
          local_1a4 = 0;
        }
        local_8 = local_8 + 1;
        break;
      case 1:
        _Str[local_1a4] = ',';
        local_1a4 = local_1a4 + 1;
        break;
      case 2:
        if (param_5 != '\0') {
          _Str[local_1a4] = '\0';
          if (local_8 < iVar2) {
            if (aiStack_19c[local_8] == 1) {
              _atol(_Str);
              FUN_00477f90();
            }
            else if (aiStack_19c[local_8] == 2) {
              basic_string<>(_Str);
              FUN_00478010(param_2,local_1ac,local_8);
            }
          }
          local_1a4 = 0;
        }
        local_c = 0;
        local_8 = local_8 + 1;
        break;
      case 3:
        local_c = 0;
        local_8 = local_8 + 1;
      }
    }
  }
  if ((local_c == 0) && (local_8 == 0)) {
    local_1ac = local_1ac + -1;
  }
  _free(_Str);
  return (local_1ac + 1) - param_3;
}

