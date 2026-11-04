
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0042a5a0(undefined4 param_1,int param_2)

{
  char *pcVar1;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  local_28[0] = DAT_007cd31d;
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  local_28[4] = '\0';
  local_28[5] = '\0';
  local_28[6] = '\0';
  local_28[7] = '\0';
  local_28[8] = '\0';
  local_28[9] = '\0';
  local_28[10] = '\0';
  local_28[0xb] = '\0';
  local_28[0xc] = '\0';
  local_28[0xd] = '\0';
  local_28[0xe] = '\0';
  local_28[0xf] = '\0';
  local_28[0x10] = '\0';
  local_28[0x11] = '\0';
  local_28[0x12] = '\0';
  local_28[0x13] = '\0';
  local_28[0x14] = '\0';
  local_28[0x15] = '\0';
  local_28[0x16] = '\0';
  local_28[0x17] = '\0';
  local_28[0x18] = '\0';
  local_28[0x19] = '\0';
  local_28[0x1a] = '\0';
  local_28[0x1b] = '\0';
  local_28[0x1c] = '\0';
  local_28[0x1d] = '\0';
  local_28[0x1e] = '\0';
  local_28[0x1f] = 0;
  if ((1 < param_2) && (param_2 < 0xb)) {
    _sprintf(local_28,"%c");
  }
  switch(param_2) {
  case 1:
    _sprintf(local_28,"ESC");
    break;
  case 0xb:
    _sprintf(local_28,"0");
    break;
  case 0xc:
    _sprintf(local_28,"-");
    break;
  case 0xe:
    _sprintf(local_28,"BS");
    break;
  case 0xf:
    _sprintf(local_28,"TAB");
    break;
  case 0x10:
    _sprintf(local_28,"Q");
    break;
  case 0x11:
    _sprintf(local_28,"W");
    break;
  case 0x12:
    _sprintf(local_28,"E");
    break;
  case 0x13:
    _sprintf(local_28,"R");
    break;
  case 0x14:
    _sprintf(local_28,"T");
    break;
  case 0x15:
    _sprintf(local_28,"Y");
    break;
  case 0x16:
    _sprintf(local_28,"U");
    break;
  case 0x17:
    _sprintf(local_28,"I");
    break;
  case 0x18:
    _sprintf(local_28,"O");
    break;
  case 0x19:
    _sprintf(local_28,"P");
    break;
  case 0x1a:
    _sprintf(local_28,"[");
    break;
  case 0x1b:
    _sprintf(local_28,"]");
    break;
  case 0x1c:
    _sprintf(local_28,"Enter");
    break;
  case 0x1d:
    basic_string<>(&DAT_007cd348);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x1e:
    _sprintf(local_28,"A");
    break;
  case 0x1f:
    _sprintf(local_28,"S");
    break;
  case 0x20:
    _sprintf(local_28,"D");
    break;
  case 0x21:
    _sprintf(local_28,"F");
    break;
  case 0x22:
    _sprintf(local_28,"G");
    break;
  case 0x23:
    _sprintf(local_28,"H");
    break;
  case 0x24:
    _sprintf(local_28,"J");
    break;
  case 0x25:
    _sprintf(local_28,"K");
    break;
  case 0x26:
    _sprintf(local_28,"L");
    break;
  case 0x27:
    basic_string<>(&DAT_007cd3c4);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x2a:
    basic_string<>(&DAT_007cd338);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x2b:
    _sprintf(local_28,"\\");
    break;
  case 0x2c:
    _sprintf(local_28,"Z");
    break;
  case 0x2d:
    _sprintf(local_28,"X");
    break;
  case 0x2e:
    _sprintf(local_28,"C");
    break;
  case 0x2f:
    _sprintf(local_28,"V");
    break;
  case 0x30:
    _sprintf(local_28,"B");
    break;
  case 0x31:
    _sprintf(local_28,"N");
    break;
  case 0x32:
    _sprintf(local_28,"M");
    break;
  case 0x33:
    basic_string<>(&DAT_007cd3dc);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x34:
    _sprintf(local_28,".");
    break;
  case 0x35:
    _sprintf(local_28,"/");
    break;
  case 0x36:
    basic_string<>(&DAT_007cd340);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x38:
    basic_string<>(&DAT_007cd3ac);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x39:
    _sprintf(local_28,"SPACE");
    break;
  case 0x3a:
    _sprintf(local_28,"Caps");
    break;
  case 0x3b:
    _sprintf(local_28,"F1");
    break;
  case 0x3c:
    _sprintf(local_28,"F2");
    break;
  case 0x3d:
    _sprintf(local_28,"F3");
    break;
  case 0x3e:
    _sprintf(local_28,"F4");
    break;
  case 0x3f:
    _sprintf(local_28,"F5");
    break;
  case 0x40:
    _sprintf(local_28,"F6");
    break;
  case 0x41:
    _sprintf(local_28,"F7");
    break;
  case 0x42:
    _sprintf(local_28,"F8");
    break;
  case 0x43:
    _sprintf(local_28,"F9");
    break;
  case 0x44:
    _sprintf(local_28,"F10");
    break;
  case 0x46:
    _sprintf(local_28,"Scroll");
    break;
  case 0x57:
    _sprintf(local_28,"F11");
    break;
  case 0x58:
    _sprintf(local_28,"F12");
    break;
  case 0x7d:
    _sprintf(local_28,"\\");
    break;
  case 0x90:
    _sprintf(local_28,"^");
    break;
  case 0x91:
    _sprintf(local_28,"@");
    break;
  case 0x92:
    basic_string<>(&DAT_007cd3c8);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0x9d:
    basic_string<>(&DAT_007cd350);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xb8:
    basic_string<>(&DAT_007cd3b4);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xc5:
    _sprintf(local_28,"Pause");
    break;
  case 199:
    _sprintf(local_28,"HOME");
    break;
  case 200:
    basic_string<>(&DAT_007cd388);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xc9:
    _sprintf(local_28,"PageUp");
    break;
  case 0xcb:
    basic_string<>(&DAT_007cd384);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xcd:
    basic_string<>(&DAT_007cd38c);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xcf:
    _sprintf(local_28,"END");
    break;
  case 0xd0:
    basic_string<>(&DAT_007cd390);
    pcVar1 = (char *)FUN_00401c50();
    _sprintf(local_28,pcVar1);
    break;
  case 0xd1:
    _sprintf(local_28,"PageDown");
    break;
  case 0xd3:
    _sprintf(local_28,"DEL");
  }
  basic_string<>();
  return param_1;
}

