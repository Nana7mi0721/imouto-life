
basic_string<char,std::char_traits<char>,std::allocator<char>_> *
FUN_004293c0(basic_string<char,std::char_traits<char>,std::allocator<char>_> *param_1,
            basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_> param_2)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_007acbec;
  local_10 = ExceptionList;
  local_8 = 1;
  ExceptionList = &local_10;
  while( true ) {
    while (iVar1 = FUN_004cbbc0(&DAT_007cd274,0), iVar1 != DAT_007d0624) {
      pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
               operator[](&param_2,iVar1 + 2);
      iVar3 = (int)*pcVar2;
      if (iVar3 < 0x15) {
        if (iVar3 == 0x14) {
          FUN_004cba30(iVar1,3,&DAT_007cd2a0);
        }
        else {
          switch(iVar3) {
          case 1:
            FUN_004cba30(iVar1,3,&DAT_007cd278);
            break;
          case 5:
            FUN_004cba30(iVar1,3,&DAT_007cd27c);
            break;
          case 6:
            FUN_004cba30(iVar1,3,&DAT_007cd280);
            break;
          case 9:
            FUN_004cba30(iVar1,3,&DAT_007cd284);
            break;
          case 0xb:
            FUN_004cba30(iVar1,3,&DAT_007cd28c);
            break;
          case 0xe:
            FUN_004cba30(iVar1,3,&DAT_007cd290);
            break;
          case 0xf:
            FUN_004cba30(iVar1,3,&DAT_007cd294);
            break;
          case 0x13:
            FUN_004cba30(iVar1,3,&DAT_007cd29c);
          }
        }
      }
      else if (iVar3 < 0x21) {
        if (iVar3 == 0x20) {
          FUN_004cba30(iVar1,3,&DAT_007cd288);
        }
        else {
          switch(iVar3) {
          case 0x15:
            FUN_004cba30(iVar1,3,&DAT_007cd2a4);
            break;
          case 0x17:
            FUN_004cba30(iVar1,3,"\\img[");
            break;
          case 0x1a:
            FUN_004cba30(iVar1,3,&DAT_007cd2b4);
            break;
          case 0x1b:
            FUN_004cba30(iVar1,3,&DAT_007cd2b8);
            break;
          case 0x1c:
            FUN_004cba30(iVar1,3,&DAT_007cd2bc);
          }
        }
      }
      else if (iVar3 == 0x138) {
        FUN_004cba30(iVar1,3,&DAT_007cd298);
      }
    }
    iVar1 = FUN_004cbbc0(&DAT_007cd2c0,0);
    if (iVar1 == DAT_007d0624) break;
    pcVar2 = std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
             operator[](&param_2,iVar1 + 2);
    switch(*pcVar2) {
    case '\x03':
      FUN_004cba30(iVar1,6,&DAT_007cd2c3);
      break;
    case '\x16':
      FUN_004cba30(iVar1,6,&DAT_007cd2c4);
      break;
    case '\x18':
      FUN_004cba30(iVar1,6,&DAT_007cd2c5);
      break;
    case '\x19':
      FUN_004cba30(iVar1,6,&DAT_007cd2c6);
      break;
    case '\x1d':
      FUN_004cba30(iVar1,6,&DAT_007cd2c7);
      break;
    case '\x1e':
      FUN_004cba30(iVar1,6,&DAT_007cd2c8);
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::
  basic_string<char,std::char_traits<char>,std::allocator<char>_>
            (param_1,(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *
                     )&param_2);
  local_8 = local_8 & 0xffffff00;
  std::basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>::
  ~basic_string<char,std::char_traits<char>,std::_DebugHeapAllocator<char>_>(&param_2);
  ExceptionList = local_10;
  return param_1;
}

