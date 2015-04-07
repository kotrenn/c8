import os, sys

DIR = 'tests'
C8 = '.c8'
TEST = '.test'
OUT = '.out'

def run(f, display):
    print f + ':\t',
    ret = 0
    try:
        c8file = DIR + '/' + f + C8
        outfile = DIR + '/' + f + OUT
        status = os.system('c8 ' + c8file + ' > ' + outfile)
        if status < 0:
            print '!ERROR!'
        else:
            test = open(DIR + '/' + f + TEST).read()
            out = open(DIR + '/' + f + OUT).read()
            if test == out:
                print 'SUCCESS'
            else:
                print 'FAILURE'
                ret = 1
            if display:
                diff_str = '*** '
                test_str = 'TEST'
                out_str = 'OUTPUT'
                test_lines = test.split('\n')
                out_lines = out.split('\n')
                line_len = max(map(len, test_lines))
                line_len = max(line_len, len(test_str))
                line_len += 1
                cur_line = ' ' * len(diff_str)
                cur_line += test_str
                cur_line += ' ' * (line_len - len(test_str))
                cur_line += '| ' + out_str
                print cur_line
                cur_line = ' ' * len(diff_str)
                cur_line += '-' * line_len
                cur_line += '+'
                cur_line += '-' * (len(out_str) + 1)
                print cur_line
                for i in range(min(len(test_lines), len(out_lines))):
                    cur_line = ' ' * len(diff_str)
                    if test_lines[i] != out_lines[i]:
                        cur_line = diff_str
                    cur_line += test_lines[i]
                    cur_line += ' ' * (line_len - len(test_lines[i]))
                    cur_line += '| '
                    cur_line += out_lines[i]
                    print cur_line
                if len(test_lines) < len(out_lines):
                    for i in range(len(test_lines), len(out_lines)):
                        cur_line = diff_str
                        cur_line += ' ' * line_len
                        cur_line += '| '
                        cur_line += out_lines[i]
                        print cur_line
                elif len(test_lines) > len(out_lines):
                    for i in range(len(out_lines), len(test_lines)):
                        cur_line = diff_str
                        cur_line += test_lines[i]
                        cur_line += ' ' * (line_len - len(test_lines[i]))
                        cur_line += '|'
                        print cur_line
    except:
        print 'TIMEOUT'
        ret = 1
    return ret

files = []

if len(sys.argv) > 1:
    files = sys.argv[1:]
else:
    files = os.listdir(DIR)
    files = filter(lambda x: x[-len(C8):] == C8, files)
    files = map(lambda x: x[:-len(C8)], files)

total = 0
for f in files:
    total += run(f, len(sys.argv) > 1)

if total > 0:
    print 'Failed ' + str(total) + ' tests'
