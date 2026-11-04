
uint FUN_00419790(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1
                 ,basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_2
                 ,uint param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  int local_18;
  uint local_10;
  uint local_c;
  
  local_c = 0xffffffff;
  pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
           operator[](param_2,0);
  bVar9 = *pcVar4 == '\x01';
  iVar5 = FUN_004e5650();
  if (iVar5 == 0) {
    local_c = 0xffffffff;
  }
  else {
    uVar6 = FUN_004e5650();
    if (uVar6 < 4) {
      iVar5 = FUN_004e5650();
      local_18 = 0;
      local_10 = param_3;
      iVar7 = FUN_004e5650();
      if (iVar7 == 1) {
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,0);
        cVar1 = *pcVar4;
        for (; (int)local_10 < iVar5; local_10 = local_10 + 1) {
          if (((local_18 == 0) && (DAT_0084b268 != 5)) &&
             (((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
               (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
              ((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
               (pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
            local_18 = 1;
LAB_004199e6:
            if ((local_18 == 0) &&
               (pcVar4 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_10), *pcVar4 == cVar1)) {
              return local_10;
            }
          }
          else {
            if (((local_18 == 1) &&
                (pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10), *pcVar4 != '\x7f')) &&
               ((pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), 0x3f < *pbVar8 &&
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), *pbVar8 < 0xfd)))) {
              local_18 = 2;
              goto LAB_004199e6;
            }
            if (((local_18 == 2) && (DAT_0084b268 != 5)) &&
               (((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
                 (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                  (pbVar8 = (byte *)std::
                                    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                    ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
                ((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
                 (pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
              local_18 = 1;
              goto LAB_004199e6;
            }
            if (((bVar9) || (local_18 == 1)) ||
               (pcVar4 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_10), *pcVar4 != '\x01')) {
              local_18 = 0;
              goto LAB_004199e6;
            }
            pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_10 + 1);
            local_10 = (int)*pcVar4 + local_10;
          }
        }
      }
      else if (iVar7 == 2) {
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,0);
        cVar1 = *pcVar4;
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,1);
        cVar2 = *pcVar4;
        for (; (int)local_10 < iVar5 + -1; local_10 = local_10 + 1) {
          if (((local_18 == 0) && (DAT_0084b268 != 5)) &&
             (((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
               (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
              ((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
               (pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
            local_18 = 1;
LAB_00419bf1:
            if (((local_18 != 2) &&
                (pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10), *pcVar4 == cVar1)) &&
               (pcVar4 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_10 + 1), *pcVar4 == cVar2)) {
              return local_10;
            }
          }
          else {
            if (((local_18 == 1) &&
                (pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10), *pcVar4 != '\x7f')) &&
               ((pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), 0x3f < *pbVar8 &&
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), *pbVar8 < 0xfd)))) {
              local_18 = 2;
              goto LAB_00419bf1;
            }
            if (((local_18 == 2) && (DAT_0084b268 != 5)) &&
               (((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
                 (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                  (pbVar8 = (byte *)std::
                                    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                    ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
                ((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
                 (pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
              local_18 = 1;
              goto LAB_00419bf1;
            }
            if (((bVar9) || (local_18 == 1)) ||
               (pcVar4 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_10), *pcVar4 != '\x01')) {
              local_18 = 0;
              goto LAB_00419bf1;
            }
            pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_10 + 1);
            local_10 = (int)*pcVar4 + local_10;
          }
        }
      }
      else if (iVar7 == 3) {
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,0);
        cVar1 = *pcVar4;
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,1);
        cVar2 = *pcVar4;
        pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_2,2);
        cVar3 = *pcVar4;
        for (; (int)local_10 < iVar5 + -2; local_10 = local_10 + 1) {
          if (((local_18 == 0) && (DAT_0084b268 != 5)) &&
             (((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
               (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
              ((pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
               (pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
            local_18 = 1;
LAB_00419e26:
            if (((local_18 != 2) &&
                (pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10), *pcVar4 == cVar1)) &&
               ((pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10 + 1), *pcVar4 == cVar2 &&
                (pcVar4 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_10 + 2), *pcVar4 == cVar3)))) {
              return local_10;
            }
          }
          else {
            if ((((local_18 == 1) &&
                 (pcVar4 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_10), *pcVar4 != '\x7f')) &&
                (pbVar8 = (byte *)std::
                                  basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                  ::operator[](param_1,local_10), 0x3f < *pbVar8)) &&
               (pbVar8 = (byte *)std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_10), *pbVar8 < 0xfd)) {
              local_18 = 2;
              goto LAB_00419e26;
            }
            if (((local_18 == 2) && (DAT_0084b268 != 5)) &&
               (((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0x80 < *pbVar8 &&
                 (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
                  (pbVar8 = (byte *)std::
                                    basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                    ::operator[](param_1,local_10), *pbVar8 < 0xa0)))) ||
                ((pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), 0xdf < *pbVar8 &&
                 (pbVar8 = (byte *)std::
                                   basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                   ::operator[](param_1,local_10), *pbVar8 < 0xfd)))))) {
              local_18 = 1;
              goto LAB_00419e26;
            }
            if (((bVar9) || (local_18 == 1)) ||
               (pcVar4 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_10), *pcVar4 != '\x01')) {
              local_18 = 0;
              goto LAB_00419e26;
            }
            pcVar4 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_10 + 1);
            local_10 = (int)*pcVar4 + local_10;
          }
        }
      }
    }
    else {
      local_c = AddRequestHeaders(param_2,param_3);
    }
  }
  return local_c;
}

