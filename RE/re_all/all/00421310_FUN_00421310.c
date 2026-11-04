
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00421310(undefined4 param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  char local_28 [32];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  local_28[0] = DAT_007cc762;
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
  iVar2 = param_2 + -100;
  if ((iVar2 < 0) || (299 < iVar2)) {
    basic_string<>(&DAT_007cc764);
    FUN_00401c50();
    basic_string<>();
  }
  else {
    if ((1 < iVar2) && (iVar2 < 0xb)) {
      _sprintf(local_28,"%c");
    }
    switch(param_2) {
    case 1:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"ESC");
      break;
    case 0xb:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"0");
      break;
    case 0xc:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"-");
      break;
    case 0xe:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"BS");
      break;
    case 0xf:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"TAB");
      break;
    case 0x10:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Q");
      break;
    case 0x11:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"W");
      break;
    case 0x12:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"E");
      break;
    case 0x13:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"R");
      break;
    case 0x14:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"T");
      break;
    case 0x15:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Y");
      break;
    case 0x16:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"U");
      break;
    case 0x17:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"I");
      break;
    case 0x18:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"O");
      break;
    case 0x19:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"P");
      break;
    case 0x1a:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"[");
      break;
    case 0x1b:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"]");
      break;
    case 0x1c:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Enter");
      break;
    case 0x1d:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc794);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x1e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"A");
      break;
    case 0x1f:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"S");
      break;
    case 0x20:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"D");
      break;
    case 0x21:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F");
      break;
    case 0x22:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"G");
      break;
    case 0x23:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"H");
      break;
    case 0x24:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"J");
      break;
    case 0x25:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"K");
      break;
    case 0x26:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"L");
      break;
    case 0x27:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc810);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x2a:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc784);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x2b:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc824);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x2c:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Z");
      break;
    case 0x2d:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"X");
      break;
    case 0x2e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"C");
      break;
    case 0x2f:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"V");
      break;
    case 0x30:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"B");
      break;
    case 0x31:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"N");
      break;
    case 0x32:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"M");
      break;
    case 0x33:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc828);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x34:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,".");
      break;
    case 0x35:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"/");
      break;
    case 0x36:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc78c);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x37:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc94c);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x38:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc7f8);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x39:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Space");
      break;
    case 0x3a:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Caps");
      break;
    case 0x3b:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F1");
      break;
    case 0x3c:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F2");
      break;
    case 0x3d:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F3");
      break;
    case 0x3e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F4");
      break;
    case 0x3f:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F5");
      break;
    case 0x40:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F6");
      break;
    case 0x41:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F7");
      break;
    case 0x42:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F8");
      break;
    case 0x43:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F9");
      break;
    case 0x44:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F10");
      break;
    case 0x46:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"Scroll");
      break;
    case 0x47:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc928);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x48:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc934);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x49:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc940);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4a:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc964);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4b:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc904);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4c:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc910);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4d:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc91c);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc958);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x4f:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc8e0);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x50:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc8ec);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x51:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc8f8);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x52:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc8d4);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x53:
                    /* WARNING: This code block may not be properly labeled as switch case */
      basic_string<>(&DAT_007cc970);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x57:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F11");
      break;
    case 0x58:
                    /* WARNING: This code block may not be properly labeled as switch case */
      _sprintf(local_28,"F12");
      break;
    case 0x70:
      basic_string<>(&DAT_007cc988);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x79:
      basic_string<>(&DAT_007cc998);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x7b:
      basic_string<>(&DAT_007cc9a4);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
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
      basic_string<>(&DAT_007cc814);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x94:
      basic_string<>(&DAT_007cc9b4);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0x9d:
      basic_string<>(&DAT_007cc79c);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xb5:
      basic_string<>(&DAT_007cc97c);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xb7:
      _sprintf(local_28,"PrintScreen");
      break;
    case 0xb8:
      basic_string<>(&DAT_007cc800);
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
      basic_string<>(&DAT_007cc7d4);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xc9:
      _sprintf(local_28,"PageUp");
      break;
    case 0xcb:
      basic_string<>(&DAT_007cc7d0);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xcd:
      basic_string<>(&DAT_007cc7d8);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xcf:
      _sprintf(local_28,"END");
      break;
    case 0xd0:
      basic_string<>(&DAT_007cc7dc);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
      break;
    case 0xd1:
      _sprintf(local_28,"PageDown");
      break;
    case 0xd3:
      _sprintf(local_28,"DEL");
    }
                    /* WARNING: This code block may not be properly labeled as switch case */
    iVar2 = _strcmp("",local_28);
    if (iVar2 == 0) {
      basic_string<>(&DAT_007cc9d4);
      pcVar1 = (char *)FUN_00401c50();
      _sprintf(local_28,pcVar1);
    }
    basic_string<>();
  }
  return param_1;
}

