
void FUN_004234d0(basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> *param_1
                 ,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  byte *pbVar3;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  int local_8;
  
  local_8 = FUN_004e5650();
  for (local_c = 0; (int)local_c < local_8; local_c = local_c + 1) {
    pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](param_1,local_c);
    switch(*pcVar2) {
    case '\x01':
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_1,local_c + 1);
      local_c = (int)*pcVar2 + local_c;
      break;
    default:
      if ((DAT_0084b268 != 5) &&
         (((pbVar3 = (byte *)std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[](param_1,local_c), 0x80 < *pbVar3 &&
           (((1 < DAT_0084b268 && (DAT_0084b268 < 5)) ||
            (pbVar3 = (byte *)std::
                              basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                              ::operator[](param_1,local_c), *pbVar3 < 0xa0)))) ||
          ((pbVar3 = (byte *)std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[](param_1,local_c), 0xdf < *pbVar3 &&
           (pbVar3 = (byte *)std::
                             basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                             ::operator[](param_1,local_c), *pbVar3 < 0xfd)))))) {
        local_c = local_c + 1;
      }
      break;
    case '\r':
      if (*param_4 == '\0') {
        FUN_004ce160(&local_c);
        local_1c = 100;
        FUN_004ce160(&local_1c);
      }
      break;
    case '<':
      if (((int)(local_c + 2) < local_8) &&
         (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[](param_1,local_c + 2), *pcVar2 == '>')) {
        pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                 operator[](param_1,local_c + 1);
        cVar1 = *pcVar2;
        if (cVar1 == 'C') {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_14 = 0x7c;
            FUN_004ce160(&local_14);
          }
          local_c = local_c + 2;
        }
        else if (cVar1 == 'L') {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_10 = 0x7b;
            FUN_004ce160(&local_10);
          }
          local_c = local_c + 2;
        }
        else if (cVar1 == 'R') {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_18 = 0x7d;
            FUN_004ce160(&local_18);
          }
          local_c = local_c + 2;
        }
      }
      break;
    case '\\':
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](param_1,local_c + 1);
      switch(*pcVar2) {
      case '!':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_c0 = 0x75;
          FUN_004ce160(&local_c0);
        }
        break;
      default:
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_c8 = 2;
          FUN_004ce160(&local_c8);
        }
        break;
      case '-':
        if ((((int)(local_c + 2) < local_8) &&
            (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 2), *pcVar2 == '[')) && (*param_4 == '\0')) {
          FUN_004ce160(&local_c);
          local_94 = 0x6b;
          FUN_004ce160(&local_94);
        }
        break;
      case '.':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_bc = 0x74;
          FUN_004ce160(&local_bc);
        }
        break;
      case '<':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_b8 = 0x71;
          FUN_004ce160(&local_b8);
        }
        break;
      case '>':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_b4 = 0x70;
          FUN_004ce160(&local_b4);
        }
        break;
      case 'A':
        if (((int)(local_c + 2) < local_8) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2), *pcVar2 == '+')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_ac = 0x84;
            FUN_004ce160(&local_ac);
          }
        }
        else if ((((int)(local_c + 2) < local_8) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 2), *pcVar2 == '-')) && (*param_4 == '\0')
                ) {
          FUN_004ce160(&local_c);
          local_b0 = 0x85;
          FUN_004ce160(&local_b0);
        }
        break;
      case 'E':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_8c = 0x69;
          FUN_004ce160(&local_8c);
        }
        break;
      case 'N':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_90 = 0x6a;
          FUN_004ce160(&local_90);
        }
        break;
      case '\\':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_20 = 1;
          FUN_004ce160(&local_20);
        }
        local_c = local_c + 1;
        break;
      case '^':
        if (*param_4 == '\0') {
          FUN_004ce160(&local_c);
          local_c4 = 0x78;
          FUN_004ce160(&local_c4);
        }
        break;
      case 'a':
        if ((((int)(local_c + 3) < local_8) &&
            (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 2), *pcVar2 == 'x')) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 3), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_a4 = 0x87;
            FUN_004ce160(&local_a4);
          }
        }
        else if ((((int)(local_c + 3) < local_8) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 2), *pcVar2 == 'y')) &&
                ((pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 3), *pcVar2 == '[' && (*param_4 == '\0')))
                ) {
          FUN_004ce160(&local_c);
          local_a8 = 0x88;
          FUN_004ce160(&local_a8);
        }
        break;
      case 'c':
        if ((((int)(local_c + 6) < local_8) &&
            (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 2), *pcVar2 == 's')) &&
           ((pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 3), *pcVar2 == 'e' &&
            (((pcVar2 = std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,local_c + 4), *pcVar2 == 'l' &&
              (pcVar2 = std::
                        basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                        operator[](param_1,local_c + 5), *pcVar2 == 'f')) &&
             (pcVar2 = std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[](param_1,local_c + 6), *pcVar2 == '[')))))) {
          FUN_004ce160(&local_c);
          local_68 = 0x1f;
          FUN_004ce160(&local_68);
        }
        else if (((int)(local_c + 2) < local_8) &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 2), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_6c = 0x65;
            FUN_004ce160(&local_6c);
          }
        }
        else if ((((int)(local_c + 4) < local_8) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 2), *pcVar2 == 'd')) &&
                ((pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 3), *pcVar2 == 'b' &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 4), *pcVar2 == '[')))) {
          FUN_004ce160(&local_c);
          local_70 = 0x33;
          FUN_004ce160(&local_70);
        }
        break;
      case 'f':
        if (((int)(local_c + 2) < local_8) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_78 = 0x67;
            FUN_004ce160(&local_78);
          }
        }
        else if (((((int)(local_c + 5) < local_8) &&
                  (pcVar2 = std::
                            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ::operator[](param_1,local_c + 2), *pcVar2 == 'o')) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 3), *pcVar2 == 'n')) &&
                (((pcVar2 = std::
                            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ::operator[](param_1,local_c + 4), *pcVar2 == 't' &&
                  (pcVar2 = std::
                            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ::operator[](param_1,local_c + 5), *pcVar2 == '[')) &&
                 (*param_4 == '\0')))) {
          FUN_004ce160(&local_c);
          local_7c = 0x66;
          FUN_004ce160(&local_7c);
        }
        break;
      case 'i':
        if (((int)(local_c + 2) < local_8) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_9c = 0x7e;
            FUN_004ce160(&local_9c);
          }
        }
        else if (((((int)(local_c + 4) < local_8) &&
                  (pcVar2 = std::
                            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                            ::operator[](param_1,local_c + 2), *pcVar2 == 'm')) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 3), *pcVar2 == 'g')) &&
                ((pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 4), *pcVar2 == '[' && (*param_4 == '\0')))
                ) {
          FUN_004ce160(&local_c);
          local_a0 = 0x7f;
          FUN_004ce160(&local_a0);
        }
        break;
      case 'm':
        if (((int)(local_c + 2) < local_8) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_80 = 0x68;
            FUN_004ce160(&local_80);
          }
        }
        else if ((((int)(local_c + 3) < local_8) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 2), *pcVar2 == 'x')) &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 3), *pcVar2 == '[')) {
          if (*param_4 == '\0') {
            FUN_004ce160(&local_c);
            local_84 = 0x82;
            FUN_004ce160(&local_84);
          }
        }
        else if ((((int)(local_c + 3) < local_8) &&
                 (pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 2), *pcVar2 == 'y')) &&
                ((pcVar2 = std::
                           basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                           ::operator[](param_1,local_c + 3), *pcVar2 == '[' && (*param_4 == '\0')))
                ) {
          FUN_004ce160(&local_c);
          local_88 = 0x83;
          FUN_004ce160(&local_88);
        }
        break;
      case 'r':
        if ((((int)(local_c + 2) < local_8) &&
            (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 2), *pcVar2 == '[')) && (*param_4 == '\0')) {
          FUN_004ce160(&local_c);
          local_98 = 0x6c;
          FUN_004ce160(&local_98);
        }
        break;
      case 's':
        if ((int)(local_c + 2) < local_8) {
          pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[](param_1,local_c + 2);
          switch(*pcVar2) {
          case '[':
            FUN_004ce160(&local_c);
            local_4c = 0x14;
            FUN_004ce160(&local_4c);
            break;
          case 'd':
            if ((((int)(local_c + 4) < local_8) &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 3), *pcVar2 == 'b')) &&
               (pcVar2 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_c + 4), *pcVar2 == '[')) {
              FUN_004ce160(&local_c);
              local_54 = 0x34;
              FUN_004ce160(&local_54);
            }
            break;
          case 'e':
            if ((((int)(local_c + 5) < local_8) &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 3), *pcVar2 == 'l')) &&
               ((pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 4), *pcVar2 == 'f' &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 5), *pcVar2 == '[')))) {
              FUN_004ce160(&local_c);
              local_50 = 0x1e;
              FUN_004ce160(&local_50);
            }
            break;
          case 'p':
            if (((int)(local_c + 3) < local_8) &&
               (pcVar2 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_c + 3), *pcVar2 == '[')) {
              if (*param_4 == '\0') {
                FUN_004ce160(&local_c);
                local_60 = 0x72;
                FUN_004ce160(&local_60);
              }
            }
            else if ((((((int)(local_c + 6) < local_8) &&
                       (pcVar2 = std::
                                 basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                 ::operator[](param_1,local_c + 3), *pcVar2 == 'a')) &&
                      (pcVar2 = std::
                                basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ::operator[](param_1,local_c + 4), *pcVar2 == 'c')) &&
                     ((pcVar2 = std::
                                basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ::operator[](param_1,local_c + 5), *pcVar2 == 'e' &&
                      (pcVar2 = std::
                                basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                                ::operator[](param_1,local_c + 6), *pcVar2 == '[')))) &&
                    (*param_4 == '\0')) {
              FUN_004ce160(&local_c);
              local_64 = 0x7a;
              FUN_004ce160(&local_64);
            }
            break;
          case 'y':
            if ((((int)(local_c + 4) < local_8) &&
                (pcVar2 = std::
                          basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                          ::operator[](param_1,local_c + 3), *pcVar2 == 's')) &&
               (pcVar2 = std::
                         basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                         operator[](param_1,local_c + 4), *pcVar2 == '[')) {
              FUN_004ce160(&local_c);
              local_58 = 0x28;
              FUN_004ce160(&local_58);
            }
            else if ((((int)(local_c + 5) < local_8) &&
                     (pcVar2 = std::
                               basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               ::operator[](param_1,local_c + 3), *pcVar2 == 's')) &&
                    ((pcVar2 = std::
                               basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               ::operator[](param_1,local_c + 4), *pcVar2 == 'S' &&
                     (pcVar2 = std::
                               basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                               ::operator[](param_1,local_c + 5), *pcVar2 == '[')))) {
              FUN_004ce160(&local_c);
              local_5c = 0x29;
              FUN_004ce160(&local_5c);
            }
          }
        }
        break;
      case 'u':
        if (((((int)(local_c + 4) < local_8) &&
             (pcVar2 = std::
                       basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                       operator[](param_1,local_c + 2), *pcVar2 == 'd')) &&
            (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                      ::operator[](param_1,local_c + 3), *pcVar2 == 'b')) &&
           (pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 4), *pcVar2 == '[')) {
          FUN_004ce160(&local_c);
          local_74 = 0x32;
          FUN_004ce160(&local_74);
        }
        break;
      case 'v':
        if ((int)(local_c + 3) < local_8) {
          pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
                   operator[](param_1,local_c + 3);
          if (*pcVar2 == '[') {
            pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2);
            switch(*pcVar2) {
            case '1':
              FUN_004ce160(&local_c);
              local_24 = 0xb;
              FUN_004ce160(&local_24);
              break;
            case '2':
              FUN_004ce160(&local_c);
              local_28 = 0xc;
              FUN_004ce160(&local_28);
              break;
            case '3':
              FUN_004ce160(&local_c);
              local_2c = 0xd;
              FUN_004ce160(&local_2c);
              break;
            case '4':
              FUN_004ce160(&local_c);
              local_30 = 0xe;
              FUN_004ce160(&local_30);
              break;
            case '5':
              FUN_004ce160(&local_c);
              local_34 = 0xf;
              FUN_004ce160(&local_34);
              break;
            case '6':
              FUN_004ce160(&local_c);
              local_38 = 0x10;
              FUN_004ce160(&local_38);
              break;
            case '7':
              FUN_004ce160(&local_c);
              local_3c = 0x11;
              FUN_004ce160(&local_3c);
              break;
            case '8':
              FUN_004ce160(&local_c);
              local_40 = 0x12;
              FUN_004ce160(&local_40);
              break;
            case '9':
              FUN_004ce160(&local_c);
              local_44 = 0x13;
              FUN_004ce160(&local_44);
            }
          }
          else {
            pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>
                     ::operator[](param_1,local_c + 2);
            if (*pcVar2 == '[') {
              FUN_004ce160(&local_c);
              local_48 = 10;
              FUN_004ce160(&local_48);
            }
          }
        }
      }
    }
  }
  return;
}

