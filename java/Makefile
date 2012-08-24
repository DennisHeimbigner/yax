
basedir=.
java.dir=${basedir}/java
c.dir=${basedir}/c

build.dir=${java.dir}/build
out.dir=${java.dir}/out

src.dir=${project.dir}/src
lib.dir=${project.dir}/libs
cli.jar=${lib.dir}/commons-cli-1.2.jar

grammars.dir=${shared.dir}/grammars
data.dir=${shared.dir}/data
tests.dir=${data.dir}/testdata
baseline.dir=${data.dir}/baseline
results.dir=${data.dir}/results

results.dir=${build.dir}/results

yax.jar=${project.dir}/yax.jar

main=yax.Main
cp=${cli.jar}
test.cp=${build.dir};${cli.jar}

all: test


init:
	mkdir -p ${build.dir}
	mkdir -p ${results.dir}

build: init
	javac -d ${build.dir} ${SRC}
	destdir="${build.dir}"
	classpath="${cp}"
	includeantruntime="false"
	/>


jar: depends="build">
	<jar jarfile="${yax.jar}">
	<fileset dir="${build.dir}/yax"/>
	</jar>


dap4.y:>
	<copy file="${grammars.dir}/dap4.y.core" tofile="./dap4.y.core"/>
	<concat destfile="dap4.y">
	<filelist dir="." files="dap4.y.hdr,dap4.y.core"/>
	</concat>
	<replace file="dap4.y" token="YYABORT" value="return YYABORT"/>
	<replace file="dap4.y" token="YYACCEPT" value="return YYACCEPT"/>
	<replace file="dap4.y" token="CHECK($$)" value=""/>
	<replace file="dap4.y" token="&lt;token&gt;" value="&lt;YaxToken&gt;"/>
	<replace file="dap4.y" token="&lt;list&gt;" value="&lt;List&gt;"/>
	<replace file="dap4.y" token="&lt;object&gt;" value="&lt;Object&gt;"/>


<!-- This is so ugly -->

test: depends="jar,testclean">
	<antcall target="testeach"><param name="TESTCASE" value="d"/></antcall>


testclean:>
	<delete dir="${results.dir}"/>
	<mkdir dir="${results.dir}"/>


<!--property name="TESTCASE" value="..."/-->
<!--property name="EXT" value="..."/-->
testeach:>
	<antcall target="exec"><param name="EXT" value="lt"/></antcall>
	<antcall target="compare"><param name="EXT" value="lt"/></antcall>


lt:>
	<java fork="true" classpath="${test.cp}" classname="yax.LexTest"
	output="${results.dir}/${TESTCASE}.lt">
	<arg value="-te"/><arg value="${tests.dir}/${TESTCASE}.xml"/>
	</java>


expr:>
	<antcall target="bison"><param name="GRAMMAR" value="expr.y"/></antcall>
	<java fork="true" classpath="${test.cp}" classname="yax.LexTest"
	output="${results.dir}/${TESTCASE}.lt">
	<arg value="-te"/><arg value="${tests.dir}/${TESTCASE}.xml"/>
	</java>


dap4: depends="dap4.y">
	<antcall target="bison"><param name="GRAMMAR" value="dap4.y"/></antcall>


diff:>
	<exec executable="diff" failonerror="false" resultproperty="diff-result">
	<arg value="-w"/><arg value="-b"/><arg value="-B"/>
	<arg value="${baseline.dir}/${TESTCASE}.${EXT}"/>
	<arg value="${results.dir}/${TESTCASE}.${EXT}"/>
	</exec>
	<condition property="${EXT}" value="true">
	<not><equals arg1="${diff-result}" arg2="1"/></not>
	</condition>


compare: depends="diff,if-true,if-false"/>

if:>
	<condition property="${EXT}">
	<filesmatch file1="${baseline.dir}/${TESTCASE}.${EXT}" file2="${results.dir}/${TESTCASE}.${EXT}"/>
	</condition>


if-true: if="${EXT}">
	<echo message="*** Pass: ${TESTCASE}.${EXT}"/>

if-false: unless="${EXT}">
	<echo message="*** Fail: ${TESTCASE}.${EXT}"/>


<!--property name="GRAMMAR" value="..."/-->
bison:>
	<exec executable="bison">
	<arg value="-Ljava"/>
	<arg value="-pDAP4"/>
	<arg value="dap4.y"/>
	<arg value="-o"/>
	<arg value="DAP4Parser.java"/>
	</exec>


clean: depends="testclean">
	<delete dir="${build.dir}"/>
	<delete file="tmp"/>
	<delete file="dap4.y.core"/>


</project>
