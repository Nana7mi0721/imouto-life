
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_00419ea0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_2)

{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  char *pcVar4;
  uint local_44;
  int local_3c;
  uint local_38;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [28];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_007abc72;
  local_10 = ExceptionList;
  local_18 = DAT_0084b484;
  ExceptionList = &local_10;
  basic_string<>();
  local_8 = 1;
  iVar1 = FUN_004e5650();
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize(local_34,iVar1 + 1);
  local_38 = 0;
  local_14 = FUN_004e5650();
  local_3c = 0;
  local_44 = 0;
  do {
    if (local_14 <= (int)local_44) {
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_34,local_38);
      *pcVar3 = '\0';
      std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
      basic_string<char,std::char_traits<char>,std::allocator<char>_>
                (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                          *)local_34);
      local_8 = local_8 & 0xffffff00;
      std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
      ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                ((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *)
                 local_34);
      ExceptionList = local_10;
      return param_1;
    }
    if ((local_3c == 0) && (DAT_0084b268 != 5)) {
      pbVar2 = (byte *)std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[](param_2,local_44);
      if (*pbVar2 < 0x81) {
LAB_00419f82:
        pbVar2 = (byte *)std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_2,local_44);
        if (0xdf < *pbVar2) {
          pbVar2 = (byte *)std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_2,local_44);
          if (*pbVar2 < 0xfd) goto LAB_00419faf;
        }
        goto LAB_00419fe2;
      }
      if ((DAT_0084b268 < 2) || (4 < DAT_0084b268)) {
        pbVar2 = (byte *)std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_2,local_44);
        if (0x9f < *pbVar2) goto LAB_00419f82;
      }
LAB_00419faf:
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_2,local_44);
      pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           *)local_34,local_38);
      *pcVar4 = *pcVar3;
      local_3c = 1;
LAB_0041a173:
      local_38 = local_38 + 1;
    }
    else {
LAB_00419fe2:
      if (local_3c == 1) {
        pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,local_44);
        if (*pcVar3 != '\x7f') {
          pbVar2 = (byte *)std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_2,local_44);
          if (0x3f < *pbVar2) {
            pbVar2 = (byte *)std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[](param_2,local_44);
            if (*pbVar2 < 0xfd) {
              pcVar3 = std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[](param_2,local_44);
              pcVar4 = std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   *)local_34,local_38);
              *pcVar4 = *pcVar3;
              local_3c = 2;
              goto LAB_0041a173;
            }
          }
        }
      }
      if ((local_3c == 2) && (DAT_0084b268 != 5)) {
        pbVar2 = (byte *)std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_2,local_44);
        if (0x80 < *pbVar2) {
          if ((DAT_0084b268 < 2) || (4 < DAT_0084b268)) {
            pbVar2 = (byte *)std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[](param_2,local_44);
            if (0x9f < *pbVar2) goto LAB_0041a0b1;
          }
LAB_0041a0de:
          pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[](param_2,local_44);
          pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               *)local_34,local_38);
          *pcVar4 = *pcVar3;
          local_3c = 1;
          goto LAB_0041a173;
        }
LAB_0041a0b1:
        pbVar2 = (byte *)std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_2,local_44);
        if (0xdf < *pbVar2) {
          pbVar2 = (byte *)std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_2,local_44);
          if (*pbVar2 < 0xfd) goto LAB_0041a0de;
        }
      }
      if (local_3c == 1) {
LAB_0041a145:
        pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,local_44);
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[]((basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             *)local_34,local_38);
        *pcVar4 = *pcVar3;
        local_3c = 0;
        goto LAB_0041a173;
      }
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_2,local_44);
      if (*pcVar3 != '\x01') goto LAB_0041a145;
      pcVar3 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_2,local_44 + 1);
      local_44 = (int)*pcVar3 + local_44;
    }
    local_44 = local_44 + 1;
  } while( true );
}

